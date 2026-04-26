#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse
using namespace std;

int main()
{
    vector<int> v;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        v.push_back(value);
    }

    cout << "\nOriginal vector: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }

    vector<int> v1 = v; 
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }

    vector<int> v2 = v; 

    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    cout << "\nReversed manually using iterators: ";
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
