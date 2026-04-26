#include <iostream>
using namespace std;

class Account {
    int accNo;
    string name;
    float balance;

    static int totalAccounts;

public:
    Account(int no, string n, float b) {
        accNo = no;
        name = n;
        balance = b;
        totalAccounts++;
    }

    void transfer(Account &toAcc, float amt) {
        if (amt <= 0) {
            cout << "Invalid amount\n";
        }
        else if (amt > balance) {
            cout << "Insufficient balance\n";
        }
        else {
            balance -= amt;
            toAcc.balance += amt;
            cout << "Transfer successful\n";
        }
    }

    void display() {
        cout << "\nAccount No: " << accNo;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    static void showTotal() {
        cout << "\nTotal Accounts: " << totalAccounts << endl;
    }
};

int Account::totalAccounts = 0;

int main() {
    int n;

    cout << "Enter number of accounts: ";
    cin >> n;

    Account* acc[100];

    // Input accounts
    for(int i = 0; i < n; i++) {
        int no;
        string name;
        float bal;

        cout << "\nEnter Account No: ";
        cin >> no;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Balance: ";
        cin >> bal;

        acc[i] = new Account(no, name, bal);
    }

    int choice;

    // LOOP MENU
    while(true) {

        cout << "\n--- MENU ---\n";
        cout << "1. Transfer Money\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Show Total Accounts\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int from, to;
                float amt;

                cout << "Enter sender index (0 to n-1): ";
                cin >> from;
                cout << "Enter receiver index (0 to n-1): ";
                cin >> to;
                cout << "Enter amount: ";
                cin >> amt;

                if(from >= 0 && from < n && to >= 0 && to < n) {
                    acc[from]->transfer(*acc[to], amt);
                } else {
                    cout << "Invalid index\n";
                }
                break;
            }

            case 2:
                for(int i = 0; i < n; i++) {
                    acc[i]->display();
                }
                break;

            case 3:
                Account::showTotal();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
                return 0;
        }
    }

    return 0;
}
