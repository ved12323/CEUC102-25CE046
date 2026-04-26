#include <iostream>
#include <string>
#include <stdexcept>   
using namespace std;

const int MAX_LOGS = 100;
string logs[MAX_LOGS];
int logIndex = 0;

void addLog(string msg)
{
    if (logIndex < MAX_LOGS)
    {
        logs[logIndex++] = msg;
    }
}

class InsufficientFundsException
{
public:
    double amount;
    InsufficientFundsException(double amt) : amount(amt) {}
};

class BankAccount {
private:
    double balance;
    double dailyWithdrawn;
    const double DAILY_LIMIT = 1000;

public:
    BankAccount(double bal = 0)
    {
        balance = bal;
        dailyWithdrawn = 0;
    }

    void deposit(double amount)
    {
        addLog("Enter deposit()");
        if (amount <= 0)
        {
            throw invalid_argument("Invalid deposit amount");
        }
        balance += amount;
        addLog("Deposit successful");
        addLog("Exit deposit()");
    }

    void withdraw(double amount)
    {
        addLog("Enter withdraw()");

        if (amount > DAILY_LIMIT - dailyWithdrawn)
        {
            throw runtime_error("Daily withdrawal limit exceeded");
        }

        if (amount > balance)
        {
            throw InsufficientFundsException(amount);
        }

        balance -= amount;
        dailyWithdrawn += amount;

        addLog("Withdrawal successful");
        addLog("Exit withdraw()");
    }

    double getBalance()
    {
        return balance;
    }
};

void performWithdraw(BankAccount &acc, double amt)
{
    addLog("Enter performWithdraw()");
    acc.withdraw(amt);
    addLog("Exit performWithdraw()");
}

void processTransaction(BankAccount &acc, double amt)
{
    addLog("Enter processTransaction()");
    performWithdraw(acc, amt);
    addLog("Exit processTransaction()");
}

void transfer(BankAccount &from, BankAccount &to, double amt)
{
    addLog("Enter transfer()");
    from.withdraw(amt);
    to.deposit(amt);
    addLog("Transfer successful");
    addLog("Exit transfer()");
}

const int MAX_TX = 50;
string txType[MAX_TX];
double txAmount[MAX_TX];
int txIndex = 0;

void recordTransaction(string type, double amt)
{
    if (txIndex < MAX_TX)
    {
        txType[txIndex] = type;
        txAmount[txIndex] = amt;
        txIndex++;
    }
}

int main()
{
    BankAccount acc1(500);
    BankAccount acc2(300);

    try {
        addLog("Start main");

        recordTransaction("Withdraw", 600);
        processTransaction(acc1, 600);   

        recordTransaction("Deposit", 200);
        acc1.deposit(200);

        recordTransaction("Transfer", 200);
        transfer(acc1, acc2, 200);

        addLog("End main");
    }

    catch (InsufficientFundsException e)
    {
        addLog("Caught InsufficientFundsException");
        cout << "Error: Insufficient funds for amount " << e.amount << endl;
    }

    catch (exception &e)
    {
        addLog("Caught standard exception");
        cout << "Error: " << e.what() << endl;
    }

    cout << "\n--- Transaction Logs (Stack Unwinding Trace) ---\n";
    for (int i = 0; i < logIndex; i++) {
        cout << logs[i] << endl;
    }

    cout << "\n--- Mini Statement ---\n";
    for (int i = 0; i < txIndex; i++) {
        cout << txType[i] << " : " << txAmount[i] << endl;
    }

    return 0;
}
