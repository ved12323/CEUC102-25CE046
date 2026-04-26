#include <iostream>
using namespace std;

class Point {
private:
    int x, y;

public:
    Point(int xVal = 0, int yVal = 0) {
        x = xVal;
        y = yVal;
    }

    Point& move(int dx, int dy) {
        x += dx;
        y += dy;
        return *this;
    }

    void display() {
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }

    friend void updateByPointer(Point* p);
};

void updateByPointer(Point* p) {
    int dx, dy;
    cout << "Enter dx and dy: ";
    cin >> dx >> dy;
    p->move(dx, dy);
}

int main() {
    int x, y, choice, dx, dy;

    cout << "Enter initial x and y: ";
    cin >> x >> y;

    Point p(x, y);

    while (choice != 4){
        cout << "\n1. Move\n";
        cout << "2. Pointer Update\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter dx1 dy1: ";
            cin >> dx >> dy;
            cout << "Enter dx2 dy2: ";
            int dx2, dy2;
            cin >> dx2 >> dy2;

            p.move(dx, dy).move(dx2, dy2);
            break;

        case 2:
            updateByPointer(&p);
            break;

        case 3:
            p.display();
            break;

        case 4:
            break;

        default:
            cout << "Invalid!\n";
        }

    } 

    return 0;
}
