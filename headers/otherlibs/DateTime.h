#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

class DateTime {
public:
    static string getCurrentTime() {
        auto now = chrono::system_clock::now();
        time_t timeNow = chrono::system_clock::to_time_t(now);
        tm* localTime = localtime(&timeNow);

        char buffer[30]; // Enough for "DD/MM/YYYY - HH:MM:SS\0"
        if (strftime(buffer, sizeof(buffer), "%d/%m/%Y - %H:%M:%S", localTime)) {
            return string(buffer);
        } else {
            return "Error formatting date/time";
        }
    }
};
