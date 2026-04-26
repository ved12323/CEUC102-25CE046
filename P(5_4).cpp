#include <iostream>
#include <iomanip>
using namespace std;

ostream& currency(ostream& out) {
    out << "Rs ";
    return out;
}

class Student {
private:
    string name;
    int marks;
    float fees;

public:
    void input() {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter marks: ";
        cin >> marks;

        cout << "Enter fees: ";
        cin >> fees;
    }

    void displayHeader() {
        cout << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');
        cout << setw(15) << "Name"
             << setw(10) << "Marks"
             << setw(15) << "Fees" << endl;
        cout << setfill('=') << setw(40) << "" << endl;
        cout << setfill(' ');
    }

    void display() {
        cout << setw(15) << name
             << setw(10) << marks
             << setw(10) << currency << fixed << setprecision(2) << fees
             << endl;
    }
};

int main() {
    Student s[5];
    int n = 0;          
    int choice = 0;

    while (choice != 3) {
        cout << "\n--- Menu ---\n";
        cout << "1. Input Students\n";
        cout << "2. Display Table\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter number of students : ";
            cin >> n;

            if (n > 5 || n <= 0) {
                cout << "Invalid number!\n";
                n = 0;
                break;
            }

            for (int i = 0; i < n; i++) {
                cout << "\nStudent " << i + 1 << endl;
                s[i].input();
            }
            break;

        case 2:
            if (n == 0) {
                cout << "No data! Please input first.\n";
                break;
            }

            s[0].displayHeader();

            for (int i = 0; i < n; i++) {
                s[i].display();
            }
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
