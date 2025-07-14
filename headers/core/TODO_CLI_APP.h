#pragma once

#include <iostream>
using namespace std;

#include "../UI/Main_UI.h"
#include "../otherlibs/clsInputValidate.h"
#include "../otherlibs/Util.h"
#include "global/global_vars.h"
#include "MainMenu\main_menu.h"

class todo_CLI : public Main_UI {
private:
    static void get_username() { username = clsInputValidate::readString("Entre Your Username: "); cout << "\n\t\tWelcome " << username << "\n\n"; }
public:
    static void start_app();
};

void todo_CLI::start_app() {
    system("cls");
    ToDoList_CLI_Main_UI();
    get_username();

    /* Constrains (Login Account Based on Username) */
    
    // press any key to go to main menu
    Util::back_to_X_menu("Main");
    
    // main_menu();
    MainMenu::MainMenu_Container();

    cout << "Program Ended\n";
}