#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Inventory {
public:
    string name;
    int quantity;
    float price;

    void addItem() {
        ofstream file("inventory.txt", ios::app);

        cout << "Enter item name: ";
        cin >> name;

        cout << "Enter quantity: ";
        cin >> quantity;

        cout << "Enter price: ";
        cin >> price;

        file << name << " " << quantity << " " << price << endl;

        file.close();
        cout << "Item added successfully.\n";
    }

    void viewItems() {
        ifstream file("inventory.txt");

        if (!file) {
            cout << "Error: File not found!\n";
            return;
        }

        cout << "\n--- Inventory List ---\n";

        while (file >> name >> quantity >> price) {
            cout << "Name: " << name 
                 << ", Qty: " << quantity 
                 << ", Price: " << price << endl;
        }

        file.close();
    }

    void searchItem() {
        ifstream file("inventory.txt");

        if (!file) {
            cout << "Error: File not found!\n";
            return;
        }

        string searchName;
        bool found = false;

        cout << "Enter item name to search: ";
        cin >> searchName;

        while (file >> name >> quantity >> price) {
            if (name == searchName) {
                cout << "Item Found!\n";
                cout << "Name: " << name 
                     << ", Qty: " << quantity 
                     << ", Price: " << price << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found!\n";
        }

        file.close();
    }
};

int main() {
    Inventory obj;
    int choice = 0;

    while (choice != 4) {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. View Items\n";
        cout << "3. Search Item\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.addItem();
            break;

        case 2:
            obj.viewItems();
            break;

        case 3:
            obj.searchItem();
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
