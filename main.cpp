#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void searchFile(const fs::path& directory, const std::string& fileName) {
    bool fileFound = false;

    // Iterate through the directory
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename() == fileName) {
            std::cout << "File found: " << entry.path() << std::endl;
            fileFound = true;
            break; // Exit the loop once the file is found
        }
    }

    if (!fileFound) {
        std::cout << "File not found: " << fileName << std::endl;
    }
}

int main() {
    int userChoice;
    std::string fileName;
    std::string pathAndFile;
    std::string textFile;
    std::string overwrite;
    int pathChoiche;
    std::string path;

    // to get the current path
    fs::path currentPath = fs::current_path();
    do {
        std::cout << "current path:" << currentPath << std::endl;
        std::cout << "\nWelcome to Axo's File Manager!\nWhat would you like to do?\n[1] Create file\n[2] Delete file\n[3] Edit file\n[4] View the text of a file\n[5] View list of files\n[6] Search for a file\n[7] Exit the file manager\n\n";
        std::cin >> userChoice;
        switch (userChoice) {
            case 1: {
                std::cout << "Enter the name of the file below, make sure to include the file extension: ";
                std::cin >> fileName;
                std::fflush;
                std::ofstream MyFile(fileName);
                MyFile.close();
                std::cout << fileName << " created in " << currentPath << std::endl;
                break;
            }
            case 2: {
                std::cout << "Enter the name of the file to delete below, make sure to include the file extension: ";
                std::cin >> fileName;
                std::fflush;
                fs::remove((fileName).c_str());
                std::cout << fileName << " deleted in " << currentPath << std::endl;
                break;
            }
            case 3: {
                std::cout << "Enter the name of the file below, make sure to include the file extension: ";
                std::cin >> fileName;
                std::fflush;
                std::ofstream MyFile(fileName);
                std::cout << "Please write in the file below:\n";
                std::cin.ignore();
                std::getline(std::cin, overwrite);
                MyFile << overwrite;
                MyFile.close();
                break;
            }
            case 4: {
                std::cout << "Enter the name of the file below, make sure to include the file extension: ";
                std::cin >> fileName;
                std::fflush;
                std::ifstream MyFile(fileName);
                while (std::getline(MyFile, textFile)) {
                    std::cout << textFile << std::endl;
                }
                MyFile.close();
                break;
            }
            case 5: {
                std::cout << "do you want to see the list files in the current path?\n[1]Yes\n[2]No\n";
                std::cin >> pathChoiche;
                std::fflush;
                if(pathChoiche == 2)
                {
                    std::cout << "insert the your custom path: ";
                    std::cin >> path;
                    std::cout << "\nHere is a list of files in the current directory:\n";
                    for (const auto &entry : fs::directory_iterator(path)) {
                        std::cout << entry.path() << std::endl;
                    }
                break;
                }

                std::cout << "Here is a list of files in the current directory:\n";
                for (const auto &entry : fs::directory_iterator(currentPath)) {
                    std::cout << entry.path() << std::endl;
                }
                break;
            }
            case 6: {
                std::cout << "do you want to search files in the current path?\n[1]Yes\n[2]No\n";
                std::cin >> pathChoiche;
                std::fflush;
                if(pathChoiche == 2)
                {
                    std::cout << "insert the path where you want to search: ";
                    std::cin >> path;
                    std::cout << "Enter the name of the file to search for (include extension): ";
                    std::cin >> fileName;
                    searchFile(path, fileName);
                break;
                }
                std::cout << "Enter the name of the file to search for (include extension): ";
                std::cin >> fileName;
                searchFile(currentPath, fileName);
                break;
            }
            case 7:
                return 0;
            default:
                std::cout << "Choose a valid option\n";
        }
    } while (true);

    return 0;
}
