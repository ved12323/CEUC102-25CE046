#include <iostream>
using namespace std;

class Base1
{
public:
    ~Base1()
    {
        cout << "Base1 Destructor Called" << endl;
    }
};

class Derived1 : public Base1
{
    int *ptr;

public:
    Derived1()
    {
        ptr = new int[5];
        cout << "Derived1 Constructor: Memory Allocated" << endl;
    }

    ~Derived1()
    {
        delete[] ptr;
        cout << "Derived1 Destructor: Memory Released" << endl;
    }
};

class Base2
{
public:
    virtual ~Base2()
    {
        cout << "Base2 Destructor Called" << endl;
    }
};

class Derived2 : public Base2
{
    int *ptr;

public:
    Derived2()
    {
        ptr = new int[5];
        cout << "Derived2 Constructor: Memory Allocated" << endl;
    }

    ~Derived2()
    {
        delete[] ptr;
        cout << "Derived2 Destructor: Memory Released" << endl;
    }
};

int main()
{
    cout << "----- Without Virtual Destructor -----" << endl;
    Base1 *b1 = new Derived1();
    delete b1;

    cout << endl;

    cout << "----- With Virtual Destructor -----" << endl;
    Base2 *b2 = new Derived2();
    delete b2;

    return 0;
}
