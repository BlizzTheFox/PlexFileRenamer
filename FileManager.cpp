#include "FileManager.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <regex>
#include <algorithm>

namespace fs = std::filesystem;


//Returns a vector string containing the paths to folders with the name "Seasons #" in a directory
std::vector<std::string> getSeasonsFolders(std::string directoryPath) {
    std::vector<std::string> output;
    //Making a regex to compare file names to
    std::regex seasonsFoldersRegex(R"(Season\s\d+)", std::regex_constants::icase);

    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            //if the file isn't a directory it will continue to the next iteration of the loop
            if (!entry.is_directory()) {
                continue;
            }
            //checks if the name of the folder matches the naming scheme of (Seasons #)
            //adds the file path to the vector string if it's a match
            std::string folderPath = entry.path().string();
            if (regex_match(entry.path().filename().string(), seasonsFoldersRegex)) {
                output.push_back(folderPath);
            }
        }
    } catch (const fs::filesystem_error& e) { //checking for errors
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) { //checking for exceptions
        std::cout << e.what() << std::endl;
    }

    return output;
}

// Returns a vector string containing the path to all the files in a directory
std::vector<std::string> getFilesInDirectory(fs::path directoryPath) {
    std::vector<std::string> output;
    try {
        //for all the files in the given directory checks if it's a regular file then adds it to the vector
        for (const auto& file : fs::directory_iterator(directoryPath)) {
            if (file.is_regular_file()) {
                output.push_back(file.path().string());
            }
        }
    } catch (const fs::filesystem_error& e) { //checking for errors
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) { //checking for exceptions
        std::cout << e.what() << std::endl;
    }

    return output;
}

// Returns the number of files in a directory
int numberOfFilesInDirectory(fs::path directoryPath) {
    using fs::directory_iterator;
    return std::distance(directory_iterator(directoryPath), directory_iterator());
}

// Outputs a sorted vector string by the numbers at the end of the file (e.g. e1, e2, e3)
std::vector<std::string> sortVector(std::vector<std::string> inputVector) {

    sort(inputVector.begin(), inputVector.end(),
        [](const std::string& lhs, const std::string& rhs) {
         return lhs.size() == rhs.size() ?
                lhs < rhs : lhs.size() < rhs.size(); } );
    return inputVector;
}