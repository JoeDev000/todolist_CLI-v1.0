#pragma once

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "../../../../otherlibs/Util.h"
#include "../../../../otherlibs/clsInputValidate.h"
#include "../../../global/global_vars.h"
#include "../../../task.h"

class ShowTaskDetails {
private:
    static void printHeader();
    static void printFooter();
    static void getTaskByID(task &, short);
public:
    static void _ShowTaskDetails();
};

void ShowTaskDetails::printFooter() {
    cout << "\t\t+===================================================================================================================================================+\n\n";
}                                                                                                                           

void ShowTaskDetails::printHeader() {
    cout << "\t\t\t\t\t\t\t\t --- Task Details ---\n";
    cout << "\t\t+===================================================================================================================================================+\n";
    cout << "\t\t|  ID  |     title       |                         Description                         |       time added      |     time Completed    |   Statue   |\n";
    cout << "\t\t+===================================================================================================================================================+\n";
}

void ShowTaskDetails::getTaskByID(task & t, short taskID) {

ifstream f(files::tasks);

    if (!f.is_open()) { cout << "Error Opening the Tasks File (read)"; return; }

string line;

    for (int i = 0; i < taskID; i++) {
        getline(f, line);
    }

    vector<string> vLine;

    vLine = clsString::Split(line, dlim);

    t.set_ID(short(stoi(vLine.at(0))));
    t.set_title(vLine.at(1));
    t.set_description(vLine.at(2));
    t.set_timeAdded(vLine.at(3));
    t.set_timeCompleted(vLine.at(4));
    t.set_isCompleted(Util::stringToBool(vLine.at(5)));
}

void ShowTaskDetails::_ShowTaskDetails() {
    
    if (last_ID == 0) {
        cout << "There Are No Tasks\n\n";
        Util::back_to_X_menu("Manage Tasks");
        return;
    }
    
    cout << "Entre Task ID you want to show details: ";
    short taskID = clsInputValidate::readIntNumberBetween(1, last_ID);

    system("cls");

task t;

    getTaskByID(t, taskID);

    printHeader();

    cout << "\t\t| " << setw(5) << left << t.get_ID() << "| " << setw(16) << left << t.get_title() << "| " << setw(60) << left << t.get_description() << "| ";
    cout << t.get_timeAdded() << " | " << t.get_timeCompleted();
    if (!t.is_Completed()) cout << " |   Active   |\n";
    else                   cout << " | Not Active |\n";

    printFooter();

    Util::back_to_X_menu("Manage Tasks");
}