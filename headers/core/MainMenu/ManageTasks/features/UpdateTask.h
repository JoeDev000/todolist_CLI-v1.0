#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../../../task.h"
#include "../../../global/global_vars.h"
#include "../../../../otherlibs/Util.h"
#include "../../../../otherlibs/clsInputValidate.h"
#include "../../../../otherlibs/DateTime.h"

class UpdateTask {
protected:
    static int updateTask_IsCompletedMember_MarkAsCompleted();
    static int updateTask_IsCompletedMember_UndoCompleted();
    
private:
    static void loadTasksFromFileToVector(vector<task>&);
    static void updateFile(vector<task>&);
    static void readUpdatedTask(task&);
    static void writeLog_Updated();
    static void writeLog_MarkAsCompleted();
    static void writeLog_UndoCompleted();

public:
    static void _UpdateTask();
};

void UpdateTask::loadTasksFromFileToVector(vector<task>& vTasks) {
ifstream f(files::tasks);

    if (!f.is_open()) { cout << "Error Opening the Tasks File (read)"; return; }

string line;
vector<string> vLine;

    vTasks.clear();

    while(getline(f, line)) {
        vLine = clsString::Split(line, dlim);
        
        task t;
            t.set_ID(short(stoi(vLine.at(0))));
            t.set_title(vLine.at(1));
            t.set_description(vLine.at(2)); 
            t.set_timeAdded(vLine.at(3));
            t.set_timeCompleted(vLine.at(4));
            t.set_isCompleted(Util::stringToBool(vLine.at(5)));
        
        vTasks.push_back(t);
    }

    f.close();
}

void UpdateTask::updateFile(vector<task>& vTasks) {
ofstream f(files::tasks);

    if (!f.is_open()) { cout << "Error Opening Tasks File (write)"; return; }

    for (task t : vTasks) {
        f << to_string(t.get_ID()) << dlim;
        f << t.get_title() << dlim;
        f << t.get_description() << dlim;
        f << t.get_timeAdded() << dlim;
        f << t.get_timeCompleted() << dlim;
        f << to_string(t.is_Completed()) << "\n";
    }

    f.close();
}

void UpdateTask::readUpdatedTask(task& T) {
string t;
string d;
    cout << "New Task Title : ";       getline(cin >> ws, t);
    cout << "New Task Description : "; getline(cin >> ws, d);

    T.set_title(t);
    T.set_description(d);
}

void UpdateTask::writeLog_Updated() {
ofstream l(files::logs, ios::app);

    if (!l.is_open()) { cout << "Error Opening Logs File (write)"; return; }

    l << "[#]" << dlim;
    l << "Task Updated" << dlim;
    l << DateTime::getCurrentTime() << endl;

    l.close();
}

void UpdateTask::writeLog_MarkAsCompleted() {
ofstream l(files::logs, ios::app);

    if (!l.is_open()) { cout << "Error Opening Logs File (write)"; return; }

    l << "[t]" << dlim;
    l << "Task Marked As Completed" << dlim;
    l << DateTime::getCurrentTime() << endl;

    l.close();
}

void UpdateTask::writeLog_UndoCompleted () {
ofstream l(files::logs, ios::app);

    if (!l.is_open()) { cout << "Error Opening Logs File (write)"; return; }

    l << "[x]" << dlim;
    l << "Task Undo Completed" << dlim;
    l << DateTime::getCurrentTime() << endl;

    l.close();
}

void UpdateTask::_UpdateTask() {
short updatedID;
    cout << "Entre the ID of the task you want to update: ";
    updatedID = clsInputValidate::readShortNumber();

    while (!clsInputValidate::IsNumberBetween(updatedID, (short)1, last_ID)) {
        cout << "Invalid Input Range, Try Again: ";
        updatedID = clsInputValidate::readShortNumber();
    }

vector<task> vTasks;
    loadTasksFromFileToVector(vTasks);

task t = vTasks.at(updatedID - 1); /* Coping the task */

    readUpdatedTask(t);

    vTasks.at(updatedID - 1) = t; /* Update Task in the vector */

    updateFile(vTasks);

    writeLog_Updated();
}

int UpdateTask::updateTask_IsCompletedMember_MarkAsCompleted() {
short updatedID;
    cout << "Entre the ID of the task you want to Mark As Completed: ";
    updatedID = clsInputValidate::readShortNumber();

    while (!clsInputValidate::IsNumberBetween(updatedID, (short)1, last_ID)) {
        cout << "Invalid Input Range, Try Again: ";
        updatedID = clsInputValidate::readShortNumber();
    }

vector<task> vTasks;
    loadTasksFromFileToVector(vTasks);

    if (vTasks.at(updatedID - 1).is_Completed()) {
        cout << "\nTask is Already Completed!\n\n";
        cout << "Press Any Key To Continue...";
        system("pause>0");
        return 1;
    }
    else {
        vTasks.at(updatedID - 1).set_isCompleted(true);
        vTasks.at(updatedID - 1).set_timeCompleted(DateTime::getCurrentTime());
    }

    updateFile(vTasks);

    writeLog_MarkAsCompleted();

    return 0;
}

int UpdateTask::updateTask_IsCompletedMember_UndoCompleted() {
short updatedID;
    cout << "Entre the ID of the task you want to Mark As Completed: ";
    updatedID = clsInputValidate::readShortNumber();

    while (!clsInputValidate::IsNumberBetween(updatedID, (short)1, last_ID)) {
        cout << "Invalid Input Range, Try Again: ";
        updatedID = clsInputValidate::readShortNumber();
    }

vector<task> vTasks;
    loadTasksFromFileToVector(vTasks);

    if (!vTasks.at(updatedID - 1).is_Completed()) {
        cout << "\nTask is Already NOT Completed!\n\n";
        cout << "Press Any Key To Continue...";
        system("pause>0");
        return 1;
    }
    else {
        vTasks.at(updatedID - 1).set_isCompleted(false);
        vTasks.at(updatedID - 1).set_timeCompleted("--/--/---- - --:--:--");
    }

    updateFile(vTasks);
    
    writeLog_UndoCompleted();

    return 0;
}