#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

#include "../../../otherlibs/DateTime.h"
#include "../../../otherlibs/clsInputValidate.h"
#include "../../../core/global/global_vars.h"

class ManageTasksUI {
private:
    static void printManageTasksMenu();
protected:
    enum enManageTasksOPERATION {enAddNewTask = 1, enDeleteTask = 2, enUpdateTask = 3, enMarkTaskAsCompleted = 4, enUndoCompletedTask = 5, enShowActiveTasks = 6, enShowTaskDetails = 7, enExit = 8};
    static enManageTasksOPERATION ManageTasks_UI();
};

void ManageTasksUI::printManageTasksMenu() {
cout << R"(
                +=====================================+
                |    TODO LIST - Manage Tasks Menu    |
                +=====================================+
                |      1- Add New Task                |
                |      2- Delete Task                 |
                |      3- Update Task                 |
                |      4- Mark Task As Completed      |
                |      5- Undo Completed Task         |
                |      6- Show Active Tasks           |
                |      7- Show Task Details           |
                |      8- Exit Manage Tasks Menu      |
                +=====================================+
)" << "\n";
    cout << "\t\tUser: " << left << setw(10) << username << "Date: " << DateTime::getCurrentTime() << "\n\n";
}

ManageTasksUI::enManageTasksOPERATION ManageTasksUI::ManageTasks_UI() {

    printManageTasksMenu();

    cout << "Choose An Operation: ";
    
    return (enManageTasksOPERATION) clsInputValidate::readShortNumberBetween(1, 8, "Invalid Input Range, Choose between [1 - 8]\n");
}