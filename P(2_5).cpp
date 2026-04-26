#include <iostream>
#include <cmath>
using namespace std;

class Loan {
    int loanID;
    string name;
    float amount, rate;
    int months;

public:
    // Parameterized Constructor ONLY
    Loan(int id, string n, float amt, float r, int m) {
        loanID = id;
        name = n;
        amount = amt;
        rate = r;
        months = m;
    }

    float calculateEMI() {
        float R = rate / (12 * 100);
        return (amount * R * pow(1 + R, months)) /
               (pow(1 + R, months) - 1);
    }

    void display() {
        cout << "\nLoan ID: " << loanID;
        cout << "\nName: " << name;
        cout << "\nLoan Amount: " << amount;
        cout << "\nInterest Rate: " << rate;
        cout << "\nMonths: " << months;
        cout << "\nEMI: " << calculateEMI() << endl;
    }
};

int main() {
    int id, m;
    string name;
    float amt, rate;

    cout << "Enter Loan ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Loan Amount: ";
    cin >> amt;

    cout << "Enter Annual Interest Rate (%): ";
    cin >> rate;

    cout << "Enter Tenure (months): ";
    cin >> m;

    // Object created using parameterized constructor
    Loan l(id, name, amt, rate, m);

    l.display();

    return 0;
}
