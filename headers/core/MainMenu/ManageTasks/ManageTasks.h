#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

#include "../../../UI/MainMenuUI/ManageTasksUI/ManageTasksUI.h"
#include "../../../otherlibs/clsString.h"
#include "../../../otherlibs/Util.h"
#include "../../global/global_vars.h"
#include "../../task.h"
#include "features/AddNewTask.h"
#include "features/DeleteTask.h"
#include "features/UpdateTask.h"
#include "features/MarkAsCompleted.h"
#include "features/UndoCompleted.h"
#include "features/ShowActiveTasks.h"
#include "features/ShowTaskDetails.h"

class ManageTasks : public ManageTasksUI {
private:
    static void showTasks();
    static void printHeader();
    static void printFooter();
    static void loadTasksFromFileToVector(vector<task>&);
public:
    static void ManageTasks_Container();
};

void ManageTasks::ManageTasks_Container() {

string msgs[5] {
    "\n\tTask Added Successfully\n\n", 
    "\n\tTask Deleted Successfully\n\n",
    "\n\tTask Updated Successfully\n\n",
    "\n\tTask Completed Successfully\n\n",
    "\n\tUndo Completed Task Was Made Successfully\n\n"
};

short op_number;

bool firstDisplay = true;

while (true) {
    system("cls");

    showTasks();

    if (!firstDisplay)
        cout << msgs[op_number];
    else
        firstDisplay = false;

    enManageTasksOPERATION p = ManageTasks_UI();
    if (p == enManageTasksOPERATION::enExit) { break; }
    switch(p) {
        case enManageTasksOPERATION::enAddNewTask: { 
            AddNewTask::_AddNewTask();
            op_number = 0;
        } 
        break;
        case enManageTasksOPERATION::enDeleteTask: {
            DeleteTask::_DeleteTask();
            op_number = 1;
        } 
        break;
        case enManageTasksOPERATION::enUpdateTask: {
            UpdateTask::_UpdateTask();
            op_number = 2;
        } 
        break;
        case enManageTasksOPERATION::enMarkTaskAsCompleted: {
            firstDisplay = MarkAsCompleted::_MarkAsCompleted();
            op_number = 3;
        }
        break;
        case enManageTasksOPERATION::enUndoCompletedTask: {
            UndoCompletedTask::_UndoCompletedTask();
            op_number = 4;
        }
        break;
        case enManageTasksOPERATION::enShowActiveTasks: {
            ShowActiveTasks::_ShowActiveTasks();
        }
        break;
        case enManageTasksOPERATION::enShowTaskDetails: {
            ShowTaskDetails::_ShowTaskDetails();
        } 
        break;
    }
}
}

void ManageTasks::printFooter() {
    cout << "\t\t+=======================================+\n\n";
}

void ManageTasks::printHeader() {
    cout << "\t\t+=======================================+\n";
    cout << "\t\t|  ID  |     title       | Is Completed |\n";
    cout << "\t\t+=======================================+\n";
}

void ManageTasks::loadTasksFromFileToVector(vector<task>& vTasks) {
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

void ManageTasks::showTasks() {
vector<task> vTasks;
    
    loadTasksFromFileToVector(vTasks);
    
    if (vTasks.empty()) {
        cout << "\t\tThere Are No Tasks Yet\n\n";
        return;
    }

    printHeader();

short counter = 0;

    for (task & t : vTasks) {
        cout << "\t\t| " << setw(5) << left << t.get_ID() << "| " << setw(16) << left << t.get_title() << "|";
        if (t.is_Completed()) cout << "     YES      ";
        else cout << "     NO       ";
        cout << "|\n";

        ++counter;
    }

    last_ID = counter;

    printFooter();
}