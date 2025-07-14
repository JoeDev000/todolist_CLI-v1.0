#pragma once

#include <iostream>
using namespace std;

#include "../../UI/MainMenuUI/main_menu_UI.h"
#include "../global/global_vars.h"
#include "../../otherlibs/Util.h"
#include "ManageTasks/ManageTasks.h"
#include "ViewLogs/ViewLogs.h"
#include "UserAnalysis/UserAnalysis.h"
#include "AboutMe/AboutMe.h"

class MainMenu : public MainMenuUI {
public:
    static void MainMenu_Container();
};

void MainMenu::MainMenu_Container() {
while (true) {
    enMainMenuOPERATION p = MainMenu_UI();
    if (p == enMainMenuOPERATION::enExit) { break; }
    switch(p) {
        case enMainMenuOPERATION::enManageTasks: {
            ManageTasks::ManageTasks_Container();
            Util::back_to_X_menu("Main");
        }
        break;
        case enMainMenuOPERATION::enViewLogs: {
            ViewLogs::_ViewLogs();
            Util::back_to_X_menu("Main");
        }
        break;
        case enMainMenuOPERATION::enUserAnalysis: {
            UserAnalysis::_UserAnalysis();
            Util::back_to_X_menu("Main");
        }
        break;
        case enMainMenuOPERATION::enAboutMe: {
            AboutMe::_AboutMe();
            Util::back_to_X_menu("Main");
        }
        break;
    }
}
}
