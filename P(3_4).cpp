#include <iostream>
using namespace std;

// Display Array
template <class T>
void display(T arr[], int n) {
    cout << "Array: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Find Maximum
template <class T>
T findMax(T arr[], int n) {
    T max = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

// Reverse Array
template <class T>
void reverseArr(T arr[], int n) {
    for(int i = 0; i < n/2; i++) {
        T temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
}

// Leader Elements
template <class T>
void leaders(T arr[], int n) {
    cout << "Leader Elements: ";
    for(int i = 0; i < n; i++) {
        bool isLeader = true;
        for(int j = i+1; j < n; j++) {
            if(arr[i] <= arr[j]) {
                isLeader = false;
                break;
            }
        }
        if(isLeader)
            cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;

    cout << "Enter size of array: ";
    cin >> n;

    int type;
    cout << "Choose Data Type:\n1. Integer\n2. Float\n3. Character\n";
    cin >> type;

    // STATIC ARRAYS
    int iarr[100];
    float farr[100];
    char carr[100];

    // Input based on type
    if(type == 1) {
        cout << "Enter integer elements:\n";
        for(int i=0;i<n;i++) cin >> iarr[i];
    }
    else if(type == 2) {
        cout << "Enter float elements:\n";
        for(int i=0;i<n;i++) cin >> farr[i];
    }
    else {
        cout << "Enter character elements:\n";
        for(int i=0;i<n;i++) cin >> carr[i];
    }

    while(true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Display\n2. Find Max\n3. Reverse\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                if(type==1) display(iarr,n);
                else if(type==2) display(farr,n);
                else display(carr,n);
                break;

            case 2:
                if(type==1) cout<<"Max="<<findMax(iarr,n)<<endl;
                else if(type==2) cout<<"Max="<<findMax(farr,n)<<endl;
                else cout<<"Max="<<findMax(carr,n)<<endl;
                break;

            case 3:
                if(type==1) reverseArr(iarr,n);
                else if(type==2) reverseArr(farr,n);
                else reverseArr(carr,n);
                cout<<"Array Reversed\n";
                break;

            case 4:
                return 0;

            default:
                cout<<"Invalid choice\n";
                return 0;
        }
    }

    return 0;
}
