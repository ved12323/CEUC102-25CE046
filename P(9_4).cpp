#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    map<string, vector<string> > directory;
    int choice = 0;
    string folderName, fileName;

    while (true)
    {
        cout << "\n===== Directory Management System =====\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display Directory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4)
        {
            cout << "Exiting program...\n";
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter folder name: ";
            cin >> folderName;

            if (directory.count(folderName) == 0)
            {
                directory[folderName] = vector<string>();
                cout << "Folder added successfully!\n";
            }
            else
            {
                cout << "Folder already exists!\n";
            }
            break;

        case 2:
            cout << "Enter folder name: ";
            cin >> folderName;

            if (directory.count(folderName))
            {
                cout << "Enter file name: ";
                cin >> fileName;

                directory[folderName].push_back(fileName);
                cout << "File added successfully!\n";
            }
            else
            {
                cout << "Folder not found!\n";
            }
            break;

        case 3:
            cout << "\n===== Directory Contents =====\n";

            if (directory.empty())
            {
                cout << "Directory is empty!\n";
            }
            else
            {
                for (map<string, vector<string> >::iterator it = directory.begin(); it != directory.end(); ++it)
                {
                    cout << "Folder: " << it->first << endl;

                    if (it->second.empty())
                    {
                        cout << "  (No files)\n";
                    }
                    else
                    {
                        for (vector<string>::iterator vit = it->second.begin(); vit != it->second.end(); ++vit)
                        {
                            cout << "  - " << *vit << endl;
                        }
                    }
                }
            }
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
