#include <iostream>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    float price;
    int quantity;

public:
    
    Item(int id = 0, string name = "NA", float p = 0.0, int q = 0) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    void addStock(int qty) {
        quantity += qty;
        cout << "Stock added successfully.\n";
    }

    void sellItem(int qty) {
        if (qty <= quantity) {
            quantity -= qty;
            cout << "Item sold successfully.\n";
        } else {
            cout << "Not enough stock!\n";
        }
    }

    void display() {
        cout << "\nID: " << itemID
             << "\nName: " << itemName
             << "\nPrice: " << price
             << "\nQuantity: " << quantity << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[10];

    for (int i = 0; i < n; i++) {
        int id, qty;
        float price;
        string name;

        cout << "\nEnter Item ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Quantity: ";
        cin >> qty;

        items[i] = Item(id, name, price, qty);
    }

    int choice, index, qty;
    do {
        cout << "\n1. Display Item";
        cout << "\n2. Add Stock";
        cout << "\n3. Sell Item";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice != 4) {
            cout << "Enter item index: ";
            cin >> index;
        }

        switch (choice) {
            case 1:
                items[index].display();
                break;
            case 2:
                cout << "Enter quantity to add: ";
                cin >> qty;
                items[index].addStock(qty);
                break;
            case 3:
                cout << "Enter quantity to sell: ";
                cin >> qty;
                items[index].sellItem(qty);
                break;
        }
    } while (choice != 4);

    return 0;
}

