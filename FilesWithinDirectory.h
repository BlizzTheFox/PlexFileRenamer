#ifndef FILES_WITHIN_DIRECTORY_H
#define FILES_WITHIN_DIRECTORY_H

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <windows.h>

using namespace std;
namespace fs = std::filesystem;

//Variables
vector<string> inline seasonsFolderVector;
vector<string> inline filesInSeasonFolder;
vector<string> inline newFileNames;
//Functions
void getSeasonsFolders(string path);
size_t numberOfFilesInDirectory(string path);

void setColour(int textColor);

//Colour Definitions
static int black = 0;
static int blue = 1;
static int green = 2;
static int aqua = 3;
static int red = 4;
static int purple = 5;
static int yellow = 6;
static int white = 7;
static int gray = 8;
static int lblue = 9;

#endif