#include "Formating.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>
#include <windows.h>

void setColour(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,(black << 4) | textColor);
}

void printColour(int textColor, std::string text) {
    setColour(textColor);
    std::cout << text;
    setColour(white);
}