#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../../../../otherlibs/Util.h"
#include "../../../global/global_vars.h"
#include "../../../task.h"

class ShowActiveTasks {
private:
    static void printHeader();
    static void printFooter();
    static void loadTasksFromFileToVector(vector<task>&);

public:
    static void _ShowActiveTasks();
};

void ShowActiveTasks::printFooter() {
    cout << "\t\t+=================================+\n\n";
}

void ShowActiveTasks::printHeader() {
    cout << "\t\t\t --- Active Tasks ---\n";
    cout << "\t\t+=================================+\n";
    cout << "\t\t|  ID  |     title       | Statue |\n";
    cout << "\t\t+=================================+\n";
}

void ShowActiveTasks::loadTasksFromFileToVector(vector<task>& vTasks) {
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

void ShowActiveTasks::_ShowActiveTasks() {
    system ("cls");

vector<task> vTasks;
    loadTasksFromFileToVector(vTasks);

    if (vTasks.empty()) {
        cout << "There Are No Tasks!! Niether Completed Nor Non-Completed\n";
        cout << "Add Some Tasks, Do Not be Lazy :(\n\n";
        Util::back_to_X_menu("Manage Tasks");
        return;
    }

vector<task> vActiveTasks;

    for (task & t : vTasks) {
        if (!t.is_Completed()) vActiveTasks.push_back(t);
    }

    if (vActiveTasks.empty()) {
        cout << "\n\nThere is No Active Tasks, All Tasks Are Doen :) - Great Job <3\n\n";
        Util::back_to_X_menu("Manage Tasks");
        return;
    }

    printHeader();

    for (task & t : vActiveTasks) {
        cout << "\t\t| " << setw(5) << left << t.get_ID() << "| " << setw(16) << left << t.get_title() << "| Active |\n";
    }

    printFooter();

    Util::back_to_X_menu("Manage Tasks");
}