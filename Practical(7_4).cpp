#include <iostream>
using namespace std;

class Shape {
public:
    virtual float area() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    Rectangle(float l = 0, float w = 0) {
        length = l;
        width = w;
    }

    float area() {
        return length * width;
    }
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r = 0) {
        radius = r;
    }

    float area() {
        return 3.14 * radius * radius;
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
            Shape* arr[5];
            int n;

            cout << "Enter number of shapes (max 5): ";
            cin >> n;

            if (n <= 0 || n > 5) {
                cout << "Invalid number!\n";
                break;
            }

            for (int i = 0; i < n; i++) {
                int type;
                cout << "\n1. Rectangle  2. Circle\n";
                cout << "Enter type: ";
                cin >> type;

                if (type == 1) {
                    float l, w;
                    cout << "Enter length and width: ";
                    cin >> l >> w;
                    arr[i] = new Rectangle(l, w);
                }
                else if (type == 2) {
                    float r;
                    cout << "Enter radius: ";
                    cin >> r;
                    arr[i] = new Circle(r);
                }
                else {
                    cout << "Invalid type!\n";
                    i--;
                }
            }

            cout << "\n--- Areas ---\n";
            for (int i = 0; i < n; i++) {
                cout << "Shape " << i + 1 << " Area = "
                     << arr[i]->area() << endl;   
                delete arr[i]; 
            }
            break;
        }

        case 2: {
            int n;
            cout << "Enter number of shapes: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid number!\n";
                break;
            }

            Shape** arr = new Shape*[n];

            for (int i = 0; i < n; i++) {
                int type;
                cout << "\n1. Rectangle  2. Circle\n";
                cout << "Enter type: ";
                cin >> type;

                if (type == 1) {
                    float l, w;
                    cout << "Enter length and width: ";
                    cin >> l >> w;
                    arr[i] = new Rectangle(l, w);
                }
                else if (type == 2) {
                    float r;
                    cout << "Enter radius: ";
                    cin >> r;
                    arr[i] = new Circle(r);
                }
                else {
                    cout << "Invalid type!\n";
                    i--;
                }
            }

            cout << "\n--- Areas ---\n";
            for (int i = 0; i < n; i++) {
                cout << "Shape " << i + 1 << " Area = "
                     << arr[i]->area() << endl;   
                delete arr[i];
            }

            delete[] arr;
            break;
        }

        case 3:
            cout << "Thank You!!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
