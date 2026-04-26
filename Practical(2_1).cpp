#include <iostream>
using namespace std;

class Rectangle {
    int l, w;

public:
    void set() {
        cout<<"Enter length and width: ";
        cin>>l>>w;
    }

    void area() {
        cout<<"Area: "<<l*w<<endl;
    }

    void perimeter() {
        cout<<"Perimeter: "<<2*(l+w)<<endl;
    }
};

int main() {
    Rectangle r;
    int ch;

    r.set();

    do {
        cout<<"\n1.Area\n2.Perimeter\n3.Exit\n";
        cin>>ch;

        if(ch==1) r.area();
        else if(ch==2) r.perimeter();

    } while(ch!=3);
}
