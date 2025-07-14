#pragma once

#include <iostream>
using namespace std;

#include "../../otherlibs/clsInputValidate.h"
#include "../../otherlibs/DateTime.h"
#include "../../core/global/global_vars.h"

class MainMenuUI {
private:
   static void printMainMenu();
protected:
enum enMainMenuOPERATION { enManageTasks = 1, enViewLogs = 2, enUserAnalysis = 3, enAboutMe = 4, enExit = 5};
    static enMainMenuOPERATION MainMenu_UI();
};

void MainMenuUI::printMainMenu() {
cout << R"(
                +=========================================+
                |          TODO LIST - Main Menu          |
                +=========================================+
                |            1- Manage Tasks              |
                |            2- View Logs                 |
                |            3- User Analysis             |
                |            4- About Me                  |
                |            5- Exit                      |
                +=========================================+
)" << "\n";
    cout << "\t\tUser: " << left << setw(10) << username << "Date: " << DateTime::getCurrentTime() << "\n\n";
}

MainMenuUI::enMainMenuOPERATION MainMenuUI::MainMenu_UI() {
    system("cls");

    printMainMenu();
    
    cout << "Choose An Operation: ";
    return (enMainMenuOPERATION) clsInputValidate::readShortNumberBetween(1, 5, "Invalid Input Range, Choose between [1 - 5]\n");
}