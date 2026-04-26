#include <iostream>
using namespace std;

class Fahrenheit; 

class Celsius {
private:
    float temp;

public:
    Celsius(float t = 0) {
        temp = t;
    }

    void input() {
        cout << "Enter temperature in Celsius: ";
        cin >> temp;
    }

    float getTemp() {
        return temp;
    }

    void display() {
        cout << temp << " C" << endl;
    }

    operator Fahrenheit();
};

class Fahrenheit {
private:
    float temp;

public:
    Fahrenheit(float t = 0) {
        temp = t;
    }

    float getTemp() {
        return temp;
    }

    void display() {
        cout << temp << " F" << endl;
    }

    operator Celsius() {
        float c = (temp - 32) * 5 / 9;
        return Celsius(c);
    }

    bool operator == (Fahrenheit f) {
        return temp == f.temp;
    }
};

Celsius::operator Fahrenheit() {
    float f = (temp * 9 / 5) + 32;
    return Fahrenheit(f);
}

class TempQueue {
private:
    float arr[10];
    int front, rear;

public:
    TempQueue() {
        front = rear = -1;
    }

    void enqueue(float x) {
        if (rear == 9) {
            cout << "Queue Full!\n";
            return;
        }

        if (front == -1) front = 0;

        arr[++rear] = x;
        cout << "Added to queue.\n";
    }

    void display() {
        if (front == -1) {
            cout << "Queue Empty!\n";
            return;
        }

        cout << "Queue Data: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Celsius c;
    Fahrenheit f, f2;

    float staticArr[10];
    int count = 0;

    TempQueue q;

    int choice = 0;

    while (choice != 6) {
        cout << "\n--- Menu ---\n";
        cout << "1. Celsius ? Fahrenheit\n";
        cout << "2. Fahrenheit ? Celsius\n";
        cout << "3. Compare Two temperatue\n";
        cout << "4. Store in Static Array\n";
        cout << "5. Store in Queue\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            c.input();
            f = c;   
            cout << "Converted: ";
            f.display();
            break;
        }

        case 2: {
            float t;
            cout << "Enter temperature in Fahrenheit: ";
            cin >> t;
            f = Fahrenheit(t);
            c = f;   
            cout << "Converted: ";
            c.display();
            break;
        }

        case 3: {
            float t1, t2;
            cout << "Enter two values: ";
            cin >> t1 >> t2;

            f = Fahrenheit(t1);
            f2 = Fahrenheit(t2);

            if (f == f2)
                cout << "Temperatures are equal\n";
            else
                cout << "Temperatures are not equal\n";
            break;
        }

        case 4: {
            if (count >= 10) {
                cout << "Array full!\n";
                break;
            }

            float val;
            cout << "Enter value to store: ";
            cin >> val;

            staticArr[count++] = val;

            cout << "Stored values: ";
            for (int i = 0; i < count; i++) {
                cout << staticArr[i] << " ";
            }
            cout << endl;
            break;
        }

        case 5: {
            float val;
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            q.display();
            break;
        }

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
