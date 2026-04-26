#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char filename[100];

    cout << "Enter file name: ";
    cin.getline(filename, 100);

    ifstream file(filename);

    if (!file) {
        cout << "Error: File does not exist or cannot be opened.\n";
        return 1;
    }

    char line[1000];
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while (file.getline(line, 1000)) {
        lineCount++;

        int i = 0;
        bool inWord = false;

        while (line[i] != '\0') {
            charCount++;


            if (line[i] != ' ' && line[i] != '\t') {
                if (!inWord) {
                    wordCount++;
                    inWord = true;
                }
            } else {
                inWord = false;
            }

            i++;
        }

        charCount++;
    }

    file.close();

    cout << "\nTotal Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}
