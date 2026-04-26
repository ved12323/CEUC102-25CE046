#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        float result;
        float denominator;
        cout << "Enter numerator and denominator: ";
        float numerator;
        cin >> numerator;
        if (cin.fail())
        {
            throw invalid_argument("Invalid input: numerator must be an integer.");
        }
        cin >> denominator;
        if (cin.fail())
        {
            throw invalid_argument("Invalid input: denominator must be an integer.");
        }
        if (denominator == 0)
        {
            throw runtime_error("Math error: Division by zero.");
        }
        result = numerator / denominator;
        cout << "Result: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "An unexpected error occurred." << endl;
    }

    return 0;
}
