#include "FilesWithinDirectory.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>
#include <windows.h>

void getSeasonsFolders(string path){
    regex seasonsFoldersRegex(R"(Season\s\d+)", regex_constants::icase);
    cout << "\nFolders Found: \n";
    setColour(gray);
    try {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (entry.is_directory()) {
                string folderName = entry.path().filename().string();
                if (regex_match(folderName, seasonsFoldersRegex)) {
                    cout << folderName << endl;
                    seasonsFolderVector.push_back(folderName);
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        cout << e.what() << endl;
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
    setColour(white);
    cout << endl;
}

size_t numberOfFilesInDirectory(string path) {
    using fs::directory_iterator;
    return distance(directory_iterator(path), directory_iterator());
}

void setColour(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,(black << 4) | textColor);
}
