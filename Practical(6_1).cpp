#include <iostream>
using namespace std;

class Shape {
protected:
    float radius;

public:
    void setRadius(float r) {
        radius = r;
    }

    float getRadius() {
        return radius;
    }
};

class Circle : public Shape {
public:
    float area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    int choice = 0;

    while (choice != 3) {
        cout << "\n--- Menu ---\n";
        cout << "1. Static Array\n";
        cout << "2. Dynamic Array\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number of circles (max 5): ";
            cin >> n;

            if (n > 5 || n <= 0) {
                cout << "Invalid number!\n";
                continue;
            }

            Circle c[5];

            for (int i = 0; i < n; i++) {
                float r;
                cout << "Enter radius of circle " << i + 1 << ": ";
                cin >> r;
                c[i].setRadius(r);
            }

            cout << "\nAreas:\n";
            for (int i = 0; i < n; i++) {
                cout << "Circle " << i + 1 
                     << " Area = " << c[i].area() << endl;
            }
        }

        else if (choice == 2) {
            int n;
            cout << "Enter number of circles: ";
            cin >> n;

            Circle* c = new Circle[n];

            for (int i = 0; i < n; i++) {
                float r;
                cout << "Enter radius of circle " << i + 1 << ": ";
                cin >> r;
                c[i].setRadius(r);
            }

            cout << "\nAreas:\n";
            for (int i = 0; i < n; i++) {
                cout << "Circle " << i + 1 
                     << " Area = " << c[i].area() << endl;
            }

            delete[] c; 
        }

        else if (choice == 3) {
            cout << "Exiting...\n";
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
