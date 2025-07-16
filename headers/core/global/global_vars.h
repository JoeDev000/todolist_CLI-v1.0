#pragma once

#include <iostream>
#include <string>
#include <filesystem>

using namespace std;

string username;
string dlim = "~";

struct files {
private:
    static string getDataPath(const string& filename) {
        namespace fs = std::filesystem;
        
        // Get current working directory
        fs::path currentPath = fs::current_path();
        
        // Check if we're running from src folder
        if (currentPath.filename() == "src") {
            // Go up one level to root, then into datafiles
            fs::path dataPath = currentPath.parent_path() / "datafiles" / filename;
            return dataPath.string();
        } else {
            // We're in root directory, directly access datafiles
            fs::path dataPath = currentPath / "datafiles" / filename;
            return dataPath.string();
        }
    }
    
public:
    static string tasks;
    static string logs;
};

// Initialize the static members with relative paths
string files::tasks = files::getDataPath("tasks.dat");
string files::logs = files::getDataPath("logs.dat");

short last_ID = 0;