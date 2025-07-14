#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

#include "../../global/global_vars.h"
#include "../../../otherlibs/clsString.h"


class ViewLogs {
private:
    static void printHeader();
    static void printFooter();

public:
    static void _ViewLogs();
};

void ViewLogs::printHeader() {
    cout << "\t\t\t--- Logs ---\n";
    cout << "+==============================================================+\n";
    cout << "|                Action                |       Date - Time     |\n";
    cout << "+==============================================================+\n";
}
void ViewLogs::printFooter() {
    cout << "+==============================================================+\n\n";
}

void ViewLogs::_ViewLogs() {
    system("cls");
ifstream l(files::logs);

    if (!l.is_open()) { cout << "Error Opening the logs file (reading)\n"; return; }

string line;
vector<string> vLine;

    if(!getline(l, line)) { cout << "There Are No Logs Yet\n"; return; }

    l.seekg(0, ios::beg);

    printHeader();

    while(getline(l, line)) {
        vLine = clsString::Split(line, dlim);
        cout << "| " << setw(37) << left << vLine.at(1) << "| " << vLine.at(2) << " |\n"; 
    }

    printFooter();
}