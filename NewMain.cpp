#include "NewMain.h"
#include "FileManager.h"
#include "Formating.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;
namespace fs = filesystem;

bool running = true;
string fileLocation[2] = {("D:\\VideosStorage\\TempDownloads"), ("D:\\VideosStorage\\TempDownloads")};
string animeName;

vector<string> seasonsFolderPaths;

void loop() {
    //asking user for relevant data (directory, anime name)
    printColour(white, "the last file location was: "); printColour(green, fileLocation[1]);
    //Directory
    printColour(aqua, "\nInput the full directory path"); printColour(white, ": ");
    getline(cin >> ws, fileLocation[0]);
    //Anime name
    printColour(aqua, "What is the name of the show/anime"); printColour(white, ": ");
    getline(cin >> ws, animeName);

    //Getting all the directories to the seasons folders
    seasonsFolderPaths = getSeasonsFolders(fileLocation[0]);

    //Displaying all the found folders
    printColour(white, "Folders found: \n");
    setColour(gray);
    for (fs::path filePath : seasonsFolderPaths) {
        cout << filePath << endl;
    }
    setColour(white);


    for (fs::path filePath : seasonsFolderPaths) {
        vector<string> filesInSeasonFolder = getFilesInDirectory(filePath);
        sortVector(filesInSeasonFolder);

        string seasonNumber = filePath.filename().string().erase(0, 7); //erase(0,7) will turn "Season #" into "#"

        //displaying the files found in the seasons folder
        printColour(aqua, "Files found in "); printColour(green, filePath.filename().string()); printColour(white, ": ");
        setColour(gray);
        for (fs::path file : filesInSeasonFolder) {
            cout << file << endl;
        }
        cout << endl << endl; setColour(white);

        //generating new file names
        string* fileExtention = new string[numberOfFilesInDirectory(filePath)];
        string* newFileName = new string[numberOfFilesInDirectory(filePath)];

        int i = 0;
        for (fs::path file : filesInSeasonFolder) {
            fileExtention[i] = file.extension().string();
            newFileName[i] = animeName + " s" + seasonNumber + "e" + to_string(i+1);
            i++;

            cout << file.string() << "\t-->\t" << file.replace_filename(newFileName[i]).replace_extension(fileExtention[i]) << endl;
        }
        char continueChoice;
        printColour(aqua, "Do you wish to continue renaming these files? "); printColour(green, "(y/n)"); printColour(white, ": ");
        cin >> continueChoice;
        if (continueChoice != 'y') { running = false; }

        i = 0;
        for (fs::path file : filesInSeasonFolder) {
            rename(file, file.replace_filename(newFileName[i]).replace_extension(fileExtention[i]));
            i++;
        }

        delete[] fileExtention;
        delete[] newFileName;
    }
}

void loopEnd() {
    //checking if the user wants to restart the program
    char restartProgramChar;
    printColour(aqua, "Do you wish to restart the program? "); printColour(green, "(y/n)"); printColour(white, ": ");
    cin >> restartProgramChar;
    if (restartProgramChar != 'y') { running = false; }
    else {
        running = true;
        fileLocation[1] = fileLocation[0];
    }
}

int main() {
    while (running) {
        loop();
        loopEnd();
    }

    return 0;
}