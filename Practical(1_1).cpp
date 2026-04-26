#include <iostream>
using namespace std;

class Wallet {
private:
    int id;
    string name;
    float balance;

public:
    void create() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void loadMoney() {
        float amt;
        cout << "Enter amount: ";
        cin >> amt;

        if (amt > 0)
            balance += amt;
        else
            cout << "Invalid amount\n";
    }

    void transfer(Wallet &w) {
        float amt;
        cout << "Enter amount to transfer: ";
        cin >> amt;

        if (amt > balance)
            cout << "Insufficient balance\n";
        else {
            balance -= amt;
            w.balance += amt;
        }
    }

    void display() {
        cout << "\nID: " << id << "\nName: " << name << "\nBalance: " << balance << endl;
    }
};

int main() {
    Wallet w1, w2;
    int choice;

    cout << "Create Wallet 1\n";
    w1.create();

    cout << "Create Wallet 2\n";
    w2.create();

    do {
        cout << "\n1.Load Money\n2.Transfer\n3.Display\n4.Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: w1.loadMoney(); break;
            case 2: w1.transfer(w2); break;
            case 3:
                cout << "\nWallet 1:"; w1.display();
                cout << "\nWallet 2:"; w2.display();
                break;
        }
    } while(choice != 4);
}
