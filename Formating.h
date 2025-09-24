#ifndef FORMATING_H
#define FORMATING_H

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>
#include <vector>
#include <windows.h>

//changes the text colour in the console
void setColour(int textColour);

//prints a string in a desired colour to the console
void printColour(int textColor, std::string text);


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

#endif //FORMATING_H
