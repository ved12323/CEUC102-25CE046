#include <iostream>
using namespace std;

class MergeArray {
private:
    int *arr1, *arr2, *merged;
    int n, m;
    bool isInputDone;

public:
    MergeArray() {
        arr1 = arr2 = merged = NULL;
        n = m = 0;
        isInputDone = false;
    }

    void input() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;

        cout << "Enter size of first array: ";
        cin >> n;

        cout << "Enter size of second array: ";
        cin >> m;

        arr1 = new int[n];
        arr2 = new int[m];
        merged = new int[n + m];

        cout << "Enter elements of first sorted array:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }

        cout << "Enter elements of second sorted array:\n";
        for (int i = 0; i < m; i++) {
            cin >> arr2[i];
        }

        isInputDone = true;
    }

    void merge() {
        if (!isInputDone) {
            cout << "Please input arrays first!\n";
            return;
        }

        int i = 0, j = 0, k = 0;

        while (i < n && j < m) {
            if (arr1[i] < arr2[j])
                merged[k++] = arr1[i++];
            else
                merged[k++] = arr2[j++];
        }

        while (i < n)
            merged[k++] = arr1[i++];

        while (j < m)
            merged[k++] = arr2[j++];

        cout << "Arrays merged successfully.\n";
    }

    void display() {
        if (!isInputDone) {
            cout << "Nothing to display!\n";
            return;
        }

        cout << "Merged Sorted Array: ";
        for (int i = 0; i < n + m; i++) {
            cout << merged[i] << " ";
        }
        cout << endl;
    }

    ~MergeArray() {
        delete[] arr1;
        delete[] arr2;
        delete[] merged;
    }
};

int main() {
    MergeArray obj;
    int choice = 0;

    while (choice != 4) {
        cout << "\n--- Menu ---\n";
        cout << "1. Input Arrays\n";
        cout << "2. Merge Arrays\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.input();
            break;

        case 2:
            obj.merge();
            break;

        case 3:
            obj.display();
            break;

        case 4:
            cout << "Thank You!!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
