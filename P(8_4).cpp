#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("data.txt");  // fixed file name

    if (!file) {
        cout << "ERROR: data.txt not found!\n";
        cout << "?? Put data.txt in SAME folder as .exe file\n";
        return 0;
    }

    string line;
    int lineNumber = 0;

    cout << "\nProcessing file...\n";

    while (getline(file, line)) {
        lineNumber++;
        stringstream ss(line);

        double num, sum = 0;
        int count = 0;

        while (ss >> num) {
            sum += num;
            count++;
        }

        if (count == 0) {
            cout << "Line " << lineNumber << " skipped (invalid data)\n";
            continue;
        }

        cout << "Line " << lineNumber
             << " -> Sum: " << sum
             << ", Avg: " << sum / count << endl;
    }

    file.close();
    return 0;
}
