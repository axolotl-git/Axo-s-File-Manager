#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int main()
{
    int userChoice;
    string fileName;
    string pathAndFile;
    string textFile;
    string overwrite;
    /*to get the current path*/
    std::filesystem::path currentPath = std::filesystem::current_path();
    do {
        cout << "current path:" <<currentPath << endl;
        cout << "\nWelcome to Axo's File Manager!\nWhat would you like to do?\n[1] Create file\n[2] Delete file\n[3] Edit file\n[4] View the text of a file\n[5] View list of files\n[6] Exit the file manager\n\n";
        cin >> userChoice;
        switch(userChoice) {
            case 1:
            {
                cout << "Enter the name of the file below, make sure to include the file extension: ";
                cin >> fileName;
                ofstream MyFile(fileName);
                MyFile.close();
                cout << fileName << " created in" <<currentPath << endl;
                break;
            }
            case 2:
            {
                cout << "Enter the name of the file to delete below, make sure to include the file extension: ";
                cin >> fileName;
                remove((fileName).c_str());
                cout << fileName << " deleted in" <<currentPath << endl;
                break;
            }
            case 3:
            {
                cout << "Enter the name of the file below, make sure to include the file extension: ";
                cin >> fileName;
                ofstream MyFile(fileName);
                cout << "Please write in the file below:\n";
                cin.ignore();
                getline(cin, overwrite);
                MyFile << overwrite;
                MyFile.close();
                break;
            }
            case 4:
            {
                cout << "Enter the name of the file below, make sure to include the file extension: ";
                cin >> fileName;
                fstream MyFile(fileName);
                while (getline(MyFile, textFile)) {
                    cout << textFile << endl;
                }
                MyFile.close();
                break;
            }
            case 5:
            {
                cout << "Here is a list of files in the current directory:\n";
                for (const auto & entry : filesystem::directory_iterator(currentPath)) {
                    std::cout << entry.path() << std::endl;
                }
                break;
            }
            case 6:
                return 0;
            default:
                cout << "Choose a valid option";
        }
    } while (true);

    return 0;
}
