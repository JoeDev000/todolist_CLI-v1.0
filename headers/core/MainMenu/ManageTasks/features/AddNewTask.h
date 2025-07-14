#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "../../../task.h"
#include "../../../../otherlibs/Util.h"
#include "../../../../otherlibs/DateTime.h"
#include "../../../global/global_vars.h"

class AddNewTask {
private:
    static void readTask(task &);
    static void writeTaskToFile(task &);
    static void writeLog();
public:
    static void _AddNewTask();
};

void AddNewTask::readTask(task & T) {
string t;
string d;
    cout << "Task Title : ";       getline(cin >> ws, t);
    cout << "Task Description : "; getline(cin >> ws, d);

    T.set_title(t);
    T.set_description(d);
    T.set_ID(++last_ID);
}

void AddNewTask::writeTaskToFile(task & T) {

ofstream f(files::tasks, ios::app);
    
    if (!f.is_open()) { cout << "Error Opening Tasks File (write)"; return; }

    f << to_string(T.get_ID()) << dlim;
    f << T.get_title() << dlim;
    f << T.get_description() << dlim;
    f << T.get_timeAdded() << dlim;
    f << T.get_timeCompleted() << dlim; 
    f << to_string(T.is_Completed()) << "\n";

    /* there is NO need to store isDeleted in the File */
    
    f.close();
}

void AddNewTask::writeLog() {
ofstream l(files::logs, ios::app);

    if (!l.is_open()) { cout << "Error Opening Logs File (write)"; return; }

    l << "[+]" << dlim;
    l << "New Task Added" << dlim;
    l << DateTime::getCurrentTime() << endl;

    l.close();
}

void AddNewTask::_AddNewTask() {
task T;
    readTask(T);
    writeTaskToFile(T);
    writeLog();
}