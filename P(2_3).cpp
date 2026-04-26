#include <iostream>
using namespace std;

class Account {
private:
    int id;
    float balance;

public:
    void create() {
        cout << "Enter ID and Balance: ";
        cin >> id >> balance;
    }

    void deposit() {
        float amt;
        cout << "Enter amount: ";
        cin >> amt;
        balance += amt;
    }

    void withdraw() {
        float amt;
        cout << "Enter amount: ";
        cin >> amt;

        if (amt > balance)
            cout << "Insufficient balance\n";
        else
            balance -= amt;
    }

    void display() {
        cout << "ID: " << id << " Balance: " << balance << endl;
    }
};

int main() {
    Account a;
    int ch;

    a.create();

    do {
        cout << "\n1.Deposit\n2.Withdraw\n3.Display\n4.Exit\nChoice: ";
        cin >> ch;

        switch(ch) {
            case 1: a.deposit(); break;
            case 2: a.withdraw(); break;
            case 3: a.display(); break;
        }
    } while(ch != 4);
}
