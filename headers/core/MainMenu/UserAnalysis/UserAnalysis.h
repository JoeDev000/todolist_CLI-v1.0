#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

#include "../../global/global_vars.h"
#include "../../../otherlibs/clsString.h"
#include "../../../otherlibs/DateTime.h"

class UserAnalysis {
private:
    static void loadLogsStatusFromFileToVector(vector<string> &, string&);
public:
    static void _UserAnalysis();
};

void UserAnalysis::loadLogsStatusFromFileToVector(vector<string>& Logs_Status, string & FirstDateTime) {
ifstream l(files::logs);
    
    if (!l.is_open()) { cout << "Error Opening the logs file (reading)\n"; return; }

string line;
vector<string> vLine;
int i = 0;
    while(getline(l, line)) {
        vLine = clsString::Split(line, dlim);
        Logs_Status.push_back(vLine.at(0));       
        if (!i++) { FirstDateTime = vLine.at(2); }
    }
}

void UserAnalysis::_UserAnalysis() {
    system("cls");

vector<string> Logs_Status;
string FisrtDateTime = "No Logs History :(";

    loadLogsStatusFromFileToVector(Logs_Status, FisrtDateTime);

short tasksAdded = 0;
short tasksDeleted = 0;
short tasksUpdated = 0;
short tasksCompleted = 0;

    for (string s : Logs_Status) {
        switch (s[1]) {
            case '+': { tasksAdded++;     } break;
            case '-': { tasksDeleted++;   } break;
            case '#': { tasksUpdated++;   } break;
            case 't': { tasksCompleted++; } break;
            case 'x': { tasksCompleted--; } break;
        }
    }

short allTasks = tasksAdded - tasksDeleted;

float avg = 0.0;

    if (allTasks != 0 ) avg = ((float)tasksCompleted / (float)allTasks) * 100.0;
    else avg = 100;

    cout << "User Name: " << username << "\n";
    cout << "-----------";
    for (int i = 0; i < username.size(); i++) { cout << "-"; }
    cout << "\nSciece: " << FisrtDateTime << endl;
    cout << "------------------------------------------------\n";
    cout << "Tasks Added:      " << setw(4) << left << tasksAdded << " Task(s)\n";
    cout << "Tasks Deleted:    " << setw(4) << left << tasksDeleted << " Task(s)\n";
    cout << "Tasks Updated:    " << setw(4) << left << tasksUpdated << " Task(s)\n";
    cout << "Tasks Completed:  " << setw(4) << left << tasksCompleted << " Task(s)\n";
    cout << "------------------------------------------------\n";
    cout << "Progress: " <<  setw(4) << left << avg << " %\n";
    cout << "------------------------------------------------\n";
    cout << "Current Date-Time: " << DateTime::getCurrentTime() << "\n\n";
}