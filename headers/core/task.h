#pragma once

#include <iostream>
#include <cstring>
using namespace std;

#include "../otherlibs/DateTime.h"

class task {
private:
    short ID;
    string title;
    string description;
    string timeAdded;
    string timeCompleted;
    bool isCompleted;
    bool isDeleted;
    
public:
    task(string t = "", string d = "") : title(t), description(d), isCompleted(false), isDeleted(false) {
        timeAdded = DateTime::getCurrentTime();
        timeCompleted = "--/--/---- - --:--:--";
    }
    void set_title (string title) { this->title = title; }
    string get_title () { return this->title; }

    void set_description (string description) { this->description = description; }
    string get_description () { return this->description; }

    void set_timeAdded (string timeAdded) { this->timeAdded = timeAdded; }
    string get_timeAdded () { return this->timeAdded; }

    void set_timeCompleted (string timeCompleted) { this->timeCompleted = timeCompleted; }
    string get_timeCompleted () { return this->timeCompleted; }

    void set_ID (short ID) { this->ID = ID; }
    short get_ID () { return this->ID; }

    void markAsDeleted() { isDeleted = true; }
    void markAsCompeted() { isCompleted = true; }
    
    bool is_Completed() { return isCompleted; }
    bool is_Deleted() { return isDeleted; }

    void set_isCompleted(bool x) { isCompleted = x; }
    void set_isDeleted(bool x) { isDeleted = x; }
};