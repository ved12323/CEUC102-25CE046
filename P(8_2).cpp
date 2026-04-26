#include <iostream>
#include <cmath>
using namespace std;

class NegativeNumberException {
public:
    void showMessage() {
        cout << "Exception: Negative number! Cannot compute square root.\n";
    }
};

class SquareRoot {
public:
    void calculate() {
        float num;

        try {
            cout << "Enter a number: ";
            cin >> num;

            if (cin.fail()) {
                throw "Invalid input!";
            }

            if (num < 0) {
                throw NegativeNumberException();
            }

            cout << "Square Root = " << sqrt(num) << endl;
        }

        catch (NegativeNumberException e) {
            e.showMessage();
        }

        catch (const char* msg) {
            cout << "Exception: " << msg << endl;
        }
    }
};

int main() {
    SquareRoot obj;
    obj.calculate();
    return 0;
}
