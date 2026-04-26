#include <iostream>
using namespace std;

int superDigit(long long n) {
    if(n < 10)
        return n;

    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

int main() {
    string n;
    int k, choice;

    cout << "1. Calculate Super Digit\n2. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {

        case 1: {
            cout << "Enter number : ";
            cin >> n;

            cout << "Enter k: ";
            cin >> k;

            long long sum = 0;

            for(int i = 0; i < n.length(); i++) {
                sum += (n[i] - '0');
            }

            sum = sum * k;

            int result = superDigit(sum);

            cout << "Super Digit = " << result << endl;
            break;
        }

        case 2:
            return 0;

        default:
            cout << "Invalid choice";
    }

    return 0;
}
