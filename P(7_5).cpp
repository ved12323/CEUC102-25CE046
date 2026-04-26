#include <iostream>
#include <string>
using namespace std;

class Grading {
protected:
    string name;
    float marks;

public:
    void input() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter marks: ";
        cin >> marks;
    }

    virtual void computeGrade() = 0;

    virtual void display() {
        cout << "Name: " << name << ", Marks: " << marks;
    }

    virtual ~Grading() {}
};

class Undergraduate : public Grading {
private:
    char grade;

public:
    void computeGrade() {
        if (marks >= 75) grade = 'A';
        else if (marks >= 60) grade = 'B';
        else if (marks >= 50) grade = 'C';
        else grade = 'F';
    }

    void display() {
        Grading::display();
        cout << ", Grade (UG): " << grade << endl;
    }
};

class Postgraduate : public Grading {
private:
    char grade;

public:
    void computeGrade() {
        if (marks >= 80) grade = 'A';
        else if (marks >= 65) grade = 'B';
        else if (marks >= 55) grade = 'C';
        else grade = 'F';
    }

    void display() {
        Grading::display();
        cout << ", Grade (PG): " << grade << endl;
    }
};

int main() {
    int choice = 0;

    while (choice != 3) {
        cout << "\n--- Menu ---\n";
        cout << "1. Static Storage\n";
        cout << "2. Dynamic Storage\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            Grading* arr[5];
            int n;

            cout << "Enter number of students (max 5): ";
            cin >> n;

            if (n <= 0 || n > 5) {
                cout << "Invalid number!\n";
                break;
            }

            for (int i = 0; i < n; i++) {
                int type;
                cout << "\n1. Undergraduate  2. Postgraduate\n";
                cout << "Enter type: ";
                cin >> type;

                if (type == 1)
                    arr[i] = new Undergraduate();
                else if (type == 2)
                    arr[i] = new Postgraduate();
                else {
                    cout << "Invalid type!\n";
                    i--;
                    continue;
                }

                arr[i]->input();
                arr[i]->computeGrade();
            }

            cout << "\n--- Student Records ---\n";
            for (int i = 0; i < n; i++) {
                arr[i]->display();  
                delete arr[i];
            }
            break;
        }

        case 2: {
            int n;
            cout << "Enter number of students: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid number!\n";
                break;
            }

            Grading** arr = new Grading*[n];

            for (int i = 0; i < n; i++) {
                int type;
                cout << "\n1. Undergraduate  2. Postgraduate\n";
                cout << "Enter type: ";
                cin >> type;

                if (type == 1)
                    arr[i] = new Undergraduate();
                else if (type == 2)
                    arr[i] = new Postgraduate();
                else {
                    cout << "Invalid type!\n";
                    i--;
                    continue;
                }

                arr[i]->input();
                arr[i]->computeGrade();
            }

            cout << "\n--- Student Records ---\n";
            for (int i = 0; i < n; i++) {
                arr[i]->display();   
                delete arr[i];
            }

            delete[] arr;
            break;
        }

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
