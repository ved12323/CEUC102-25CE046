#include <iostream>
using namespace std;

class Calculator {
private:
    float results[20];   
    int count;

public:
    Calculator() {
        count = 0;
    }

    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    float add(int a, float b) {
        return a + b;
    }

    float add(float a, int b) {
        return a + b;
    }

    void storeResult(float r) {
        if (count < 20) {
            results[count++] = r;
        }
    }

    void displayResults() {
        if (count == 0) {
            cout << "No results stored!\n";
            return;
        }

        cout << "\n--- Results ---\n";
        for (int i = 0; i < count; i++) {
            cout << "Result " << i + 1 << " = " << results[i] << endl;
        }
    }
};

int main() {
    Calculator c;
    int choice = 0;

    while (choice != 5) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Integers\n";
        cout << "2. Add Floats\n";
        cout << "3. Add Int + Float\n";
        cout << "4. Display Results\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int a, b;
            cout << "Enter two integers: ";
            cin >> a >> b;
            float res = c.add(a, b);
            c.storeResult(res);
            cout << "Result: " << res << endl;
            break;
        }

        case 2: {
            float a, b;
            cout << "Enter two floats: ";
            cin >> a >> b;
            float res = c.add(a, b);
            c.storeResult(res);
            cout << "Result: " << res << endl;
            break;
        }

        case 3: {
            int a;
            float b;
            cout << "Enter int and float: ";
            cin >> a >> b;
            float res = c.add(a, b);
            c.storeResult(res);
            cout << "Result: " << res << endl;
            break;
        }

        case 4:
            c.displayResults();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
