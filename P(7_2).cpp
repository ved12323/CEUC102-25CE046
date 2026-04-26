#include <iostream>
using namespace std;

class Complex {
private:
    float real, imag;

public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

    void input() {
        cout << "Enter real part: ";
        cin >> real;
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        cout << real;
        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";
        cout << endl;
    }

    Complex operator + (Complex c) {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    Complex operator - (Complex c) {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
};

int main() {
    Complex c1, c2, result;
    int choice = 0;

    while (choice != 4) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Complex Numbers\n";
        cout << "2. Subtract Complex Numbers\n";
        cout << "3. Display Last Result\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\nFirst Complex Number:\n";
            c1.input();
            cout << "Second Complex Number:\n";
            c2.input();

            result = c1 + c2;   
            cout << "Result: ";
            result.display();
            break;

        case 2:
            cout << "\nFirst Complex Number:\n";
            c1.input();
            cout << "Second Complex Number:\n";
            c2.input();

            result = c1 - c2;   
            cout << "Result: ";
            result.display();
            break;

        case 3:
            cout << "Last Result: ";
            result.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
