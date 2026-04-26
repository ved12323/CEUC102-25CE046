#include <iostream>
using namespace std;

class Book {
private:
    int id, copies;
    string title;

public:
    void add() {
        cout << "Enter ID: ";
		cin >> id;
		cout << "Title: ";
		cin >> title;
		cout << "Copies: ";
        cin >> copies;
    }

    void issue() {
        if (copies > 0)
            copies--;
        else
            cout << "No copies\n";
    }

    void returnBook() {
        copies++;
    }

    void display() {
        cout << id << " " << title << " Copies: " << copies << endl;
    }
};

int main() {
    Book b;
    int ch;

    b.add();

    do {
        cout << "\n1.Issue\n2.Return\n3.Display\n4.Exit\nChoice: ";
        cin >> ch;

        switch(ch) {
            case 1: b.issue(); break;
            case 2: b.returnBook(); break;
            case 3: b.display(); break;
        }
    } while(ch != 4);
}
