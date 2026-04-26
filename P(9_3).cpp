#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, value;
    vector<int> v;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    cout << "\nOriginal list: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }

    set<int> s(v.begin(), v.end());

    cout << "\n\nUnique elements (using set): ";
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }

    vector<int> uniqueVec(s.begin(), s.end());

    cout << "\n\nConverted back to vector: ";
    for (vector<int>::iterator it = uniqueVec.begin(); it != uniqueVec.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
