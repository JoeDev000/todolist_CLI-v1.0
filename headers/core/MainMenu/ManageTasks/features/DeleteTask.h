#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../../../global/global_vars.h"
#include "../../../task.h"
#include "../../../../otherlibs/Util.h"
#include "../../../../otherlibs/DateTime.h"
#include "../../../../otherlibs/clsInputValidate.h"

class DeleteTask {
private:
    static void loadTasksFromFileToVector(vector<task>&);
    static void updateFile(vector<task>&, short);
    static void writeLog();

public:
    static void _DeleteTask();
};

void DeleteTask::loadTasksFromFileToVector(vector<task>& vTasks) {
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

void DeleteTask::updateFile(vector<task>& vTasks, short deletedID) {
ofstream f(files::tasks);

    if (!f.is_open()) { cout << "Error Opening Tasks File (write)"; return; }

short counter = 0;

    for (task t : vTasks) {

        if (!t.is_Deleted()) {
            /* ID is from 1 to N sequentially */
            f << to_string(++counter) << dlim;
            
            f << t.get_title() << dlim;
            f << t.get_description() << dlim;
            f << t.get_timeAdded() << dlim;
            f << t.get_timeCompleted() << dlim;
            f << to_string(t.is_Completed()) << "\n";
        }
    }

    f.close();
}

void DeleteTask::writeLog() {
ofstream l(files::logs, ios::app);

    if (!l.is_open()) { cout << "Error Opening Logs File (write)"; return; }

    l << "[-]" << dlim;
    l << "Task Deleted" << dlim;
    l << DateTime::getCurrentTime() << endl;

    l.close();
}

void DeleteTask::_DeleteTask() {
short deletedID;
    cout << "Entre the ID of the task you want to delete: ";
    deletedID = clsInputValidate::readShortNumber();

    while (!clsInputValidate::IsNumberBetween(deletedID, (short)1, last_ID)) {
        cout << "Invalid Input Range, Try Again: ";
        deletedID = clsInputValidate::readShortNumber();
    }

vector<task> vTasks;
    loadTasksFromFileToVector(vTasks);

    vTasks.at(deletedID - 1).set_isDeleted(true);

    updateFile(vTasks, deletedID);

    writeLog();
    
    last_ID --; /* at this point it stores the number of the last ID */
}