#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int empID;

public:
    Employee(string n = "", int a = 0, int id = 0)
        : Person(n, a) {
        empID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << empID << endl;
    }

    int getID() {
        return empID;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    Manager(string n = "", int a = 0, int id = 0, string dept = "")
        : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
        cout << "----------------------\n";
    }
};

int main() {
    Manager m[5];
    int n = 0;
    int choice = 0;

    while (choice != 4) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Managers\n";
        cout << "2. Display All\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            cout << "Enter number of managers (max 5): ";
            cin >> n;

            if (n <= 0 || n > 5) {
                cout << "Invalid number!\n";
                n = 0;
                break;
            }

            for (int i = 0; i < n; i++) {
                string name, dept;
                int age, id;

                cout << "\nManager " << i + 1 << endl;

                cout << "Enter name: ";
                cin >> name;

                cout << "Enter age: ";
                cin >> age;

                cout << "Enter employee ID: ";
                cin >> id;

                cout << "Enter department: ";
                cin >> dept;

                m[i] = Manager(name, age, id, dept);
            }
            break;
        }

        case 2: {
            if (n == 0) {
                cout << "No data!\n";
                break;
            }

            cout << "\n--- Manager Details ---\n";
            for (int i = 0; i < n; i++) {
                m[i].displayManager();
            }
            break;
        }

        case 3: {
            if (n == 0) {
                cout << "No data!\n";
                break;
            }

            int searchID;
            cout << "Enter ID to search: ";
            cin >> searchID;

            bool found = false;

            for (int i = 0; i < n; i++) {
                if (m[i].getID() == searchID) {
                    cout << "\nManager Found:\n";
                    m[i].displayManager();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Manager not found!\n";
            }
            break;
        }

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
