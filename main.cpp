#include "FileManager.h"
#include "Formating.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std; //bite it's me less typing
namespace fs = filesystem; //bite me again it's less typing

bool running = true;
string fileLocation[2] = {("D:\\Media\\Anime Or Show Name"), ("D:\\Media\\Anime Or Show Name")};
string animeName;

vector<string> seasonsFolderPaths;

int main() {
    //Giving some information
    printColour(aqua, "Welcome to Plex File Renamer!\n");
    printColour(white,"Info about how the program works is in ReadMe.txt\n\n");

    while (running) {
        //asking user for relevant data (directory)
        printColour(white, "The last/example file location was: "); printColour(green, fileLocation[1]);

        //Directory
        printColour(aqua, "\nInput the full directory path"); printColour(white, ": ");
        getline(cin >> ws, fileLocation[0]);

        //Anime name
        fs::path directory = fileLocation[0];
        animeName = directory.filename().string();

        //Getting all the directories to the seasons folders
        seasonsFolderPaths = getSeasonsFolders(fileLocation[0]);

        //Displaying all the found folders
        printColour(aqua, "Folders found"); printColour(white, ": \n");
        setColour(gray);
        for (fs::path filePath : seasonsFolderPaths) {
            cout << filePath.string() << endl;
        }
        setColour(white);

        for (fs::path filePath : seasonsFolderPaths) {
            vector<string> filesInSeasonFolder = getFilesInDirectory(filePath);
            filesInSeasonFolder = sortVector(filesInSeasonFolder);

            string seasonNumber = filePath.filename().string().erase(0, 7); //erase(0,7) will turn "Season #" into "#"

            //displaying the files found in the seasons folder
            printColour(aqua, "\nFiles found in "); printColour(green, filePath.filename().string()); printColour(white, ": \n");
            setColour(gray);
            for (fs::path file : filesInSeasonFolder) {
                cout << file.string() << endl;
            }
            cout << "\n\n"; setColour(white);

            //generating new file names
            vector<string> fileExtention;
            vector<string> newFileName;
            int i = 0;

            printColour(aqua, "New names for the files in "); printColour(green, filePath.string()); printColour(white, ": \n");
            for (fs::path file : filesInSeasonFolder) {
                fileExtention.push_back(file.extension().string());
                newFileName.push_back(animeName + " s" + seasonNumber + "e" + to_string(i+1));

                //displaying the new names for the files
                cout << file.filename().string() << "\t\t-->\t\t" << file.replace_filename(newFileName[i]).replace_extension(fileExtention[i]).filename().string() << endl;
                i++;
            }

            //Checking if the user wishes to continue renaming the files
            char continueChoice;
            printColour(aqua, "Do you wish to continue renaming these files? "); printColour(green, "(y/n)"); printColour(white, ": ");
            cin >> continueChoice;
            if (continueChoice != 'y') { break; }

            //Renaming files
            i = 0;
            for (fs::path file : filesInSeasonFolder) {
                fs::path oldFilePath = file;
                fs::path newFilePath = file.replace_filename(newFileName[i]).replace_extension(fileExtention[i]);
                rename(oldFilePath, newFilePath);
                i++;
            }
        }
            //checking if the user wants to restart the program
            char restartProgramChar;
            printColour(aqua, "Do you wish to restart the program? "); printColour(green, "(y/n)"); printColour(white, ": ");
            cin >> restartProgramChar;
            if (restartProgramChar != 'y') {
                running = false;
            } else {
                running = true;
                fileLocation[1] = fileLocation[0];
            }
    }

    return 0;
}