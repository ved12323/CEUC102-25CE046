#include <iostream>
using namespace std;

class Student{
    int roll; float m1,m2,m3;
public:
    void input(){
        cout << "Enter roll : ";
        cin>>roll ;
		cout << "Enter marks : ";
		cin>> m1>>m2>>m3;
    }
    void show(){
        cout<<"Avg="<<(m1+m2+m3)/3;
    }
};

int main(){
    Student s; int ch;

    cout << "1.Input 2.Display\n";
    cout << "Enter your choice : ";
    cin >> ch;

    switch(ch){
        case 1:
			s.input(); 
			break;
        case 2:
			s.show();
    }
}
