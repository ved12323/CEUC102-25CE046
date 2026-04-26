#include <iostream>
#include <string>
using namespace std;

class Fuel {
protected:
    string fuelType;

public:
    Fuel(string f = "") {
        fuelType = f;
    }

    void displayFuel() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Brand {
protected:
    string brandName;

public:
    Brand(string b = "") {
        brandName = b;
    }

    void displayBrand() {
        cout << "Brand: " << brandName << endl;
    }
};

class Car : public Fuel, public Brand {
public:
    Car(string f = "", string b = "") : Fuel(f), Brand(b) {}

    void displayCar() {
        displayBrand();
        displayFuel();
        cout << "----------------------\n";
    }
};

int main() {
    int choice = 0;

    while (choice != 3) {
        cout << "\n--- Menu ---\n";
        cout << "1. Static Method\n";
        cout << "2. Dynamic Method\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {   
            int n;
            cout << "Enter number of cars (max 5): ";
            cin >> n;

            if (n <= 0 || n > 5) {
                cout << "Invalid number!\n";
                break;
            }

            Car c[5];

            for (int i = 0; i < n; i++) {
                string fuel, brand;

                cout << "\nCar " << i + 1 << endl;

                cout << "Enter brand: ";
                cin >> brand;

                cout << "Enter fuel type: ";
                cin >> fuel;

                c[i] = Car(fuel, brand);
            }

            cout << "\n--- Car Details ---\n";
            for (int i = 0; i < n; i++) {
                c[i].displayCar();
            }
            break;
        }

        case 2: {   
            int n;
            cout << "Enter number of cars: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid number!\n";
                break;
            }

            Car* c = new Car[n];

            for (int i = 0; i < n; i++) {
                string fuel, brand;

                cout << "\nCar " << i + 1 << endl;

                cout << "Enter brand: ";
                cin >> brand;

                cout << "Enter fuel type: ";
                cin >> fuel;

                c[i] = Car(fuel, brand);
            }

            cout << "\n--- Car Details ---\n";
            for (int i = 0; i < n; i++) {
                c[i].displayCar();
            }

            delete[] c; 
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
