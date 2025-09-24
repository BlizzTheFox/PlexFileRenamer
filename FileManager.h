#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <filesystem>
#include <vector>
#include <regex>

namespace fs = std::filesystem;

// Returns a vector string containing the paths to folders with the name "Seasons #" in a directory
std::vector<std::string> getSeasonsFolders(std::string directoryPath);

// Returns a vector string containing the path to all the files in a directory
std::vector<std::string> getFilesInDirectory(fs::path directoryPath);

// Returns the number of files in a directory
int numberOfFilesInDirectory(fs::path directoryPath);

// Outputs a sorted vector string by the numbers at the end of the file (eg e1, e2, e3)
std::vector<std::string> sortVector(std::vector<std::string> inputVector);


#endif //FILEMANAGER_H
