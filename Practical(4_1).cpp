#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    DynamicArray() {
        arr = NULL;
        size = 0;
    }

    void insert(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Element inserted successfully.\n";
    }

    void remove(int position) {
        if (position < 0 || position >= size) {
            cout << "Invalid position!\n";
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != position) {
                newArr[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = newArr;
        size--;

        cout << "Element deleted successfully.\n";
    }

    void display() {
        if (size == 0) {
            cout << "Array is empty.\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
    DynamicArray obj;
    int choice, value, position;

    do {
        cout << "\n--- Dynamic Array Menu ---\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            obj.insert(value);
            break;

        case 2:
            cout << "Enter position to delete (0-based): ";
            cin >> position;
            obj.remove(position);
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

    } while (choice != 4);

    return 0;
}
