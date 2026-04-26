#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accNo;
    float balance;

    char type[10];   
    float amount[10];
    int count;

public:
    Account(int a = 0, float b = 0) {
        accNo = a;
        balance = b;
        count = 0;
    }

    void deposit(float amt) {
        balance += amt;

        if (count < 10) {
            type[count] = 'D';
            amount[count] = amt;
            count++;
        }

        cout << "Deposited: " << amt << endl;
    }

    virtual void withdraw(float amt) {
        if (amt > balance) {
            cout << "Insufficient balance!\n";
            return;
        }

        balance -= amt;

        if (count < 10) {
            type[count] = 'W';
            amount[count] = amt;
            count++;
        }

        cout << "Withdrawn: " << amt << endl;
    }

    void showHistory() {
        cout << "\nTransaction History:\n";
        for (int i = 0; i < count; i++) {
            if (type[i] == 'D')
                cout << "Deposit: " << amount[i] << endl;
            else
                cout << "Withdraw: " << amount[i] << endl;
        }
    }

    void undo() {
        if (count == 0) {
            cout << "No transaction to undo!\n";
            return;
        }

        count--;  

        if (type[count] == 'D') {
            balance -= amount[count];  
            cout << "Undo Deposit of " << amount[count] << endl;
        }
        else {
            balance += amount[count];  
            cout << "Undo Withdraw of " << amount[count] << endl;
        }
    }

    void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }

    ~Account() {
        cout << "Account closed.\n";
    }
};
class Savings : public Account {
private:
    float interestRate;

public:
    Savings(int a = 0, float b = 0, float r = 0)
        : Account(a, b) {
        interestRate = r;
    }

    void displaySavings() {
        display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

class Current : public Account {
private:
    float overdraft;

public:
    Current(int a = 0, float b = 0, float o = 0)
        : Account(a, b) {
        overdraft = o;
    }

    void withdraw(float amt) {
        if (amt > balance + overdraft) {
            cout << "Overdraft limit exceeded!\n";
            return;
        }

        balance -= amt;

        if (count < 10) {
            type[count] = 'W';
            amount[count] = amt;
            count++;
        }

        cout << "Withdrawn: " << amt << endl;
    }

    void displayCurrent() {
        display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {
    Savings s(101, 1000, 5);
    Current c(201, 2000, 500);

    int choice = 0;

    while (choice != 8) {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit (Savings)\n";
        cout << "2. Withdraw (Savings)\n";
        cout << "3. Deposit (Current)\n";
        cout << "4. Withdraw (Current)\n";
        cout << "5. Display Accounts\n";
        cout << "6. Show History\n";
        cout << "7. Undo Last Transaction\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        float amt;

        switch (choice) {

        case 1:
            cout << "Enter amount: ";
            cin >> amt;
            s.deposit(amt);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amt;
            s.withdraw(amt);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amt;
            c.deposit(amt);
            break;

        case 4:
            cout << "Enter amount: ";
            cin >> amt;
            c.withdraw(amt);
            break;

        case 5:
            cout << "\n--- Savings ---\n";
            s.displaySavings();
            cout << "\n--- Current ---\n";
            c.displayCurrent();
            break;

        case 6:
            cout << "\nSavings History:";
            s.showHistory();
            cout << "\nCurrent History:";
            c.showHistory();
            break;

        case 7:
            cout << "\nUndo Savings:\n";
            s.undo();
            cout << "Undo Current:\n";
            c.undo();
            break;

        case 8:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
