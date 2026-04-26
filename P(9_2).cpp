#include <iostream>
#include <map>
#include <sstream>  
#include <string>
#include <cctype>   
using namespace std;

string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main()
{
    string sentence;

    cout << "Enter a sentence:\n";
    getline(cin, sentence);

    map<string, int> wordCount;

    stringstream ss(sentence);
    string word;

    while (ss >> word)
    {
        word = toLowerCase(word); 
        wordCount[word]++;
    }

    cout << "\nWord Frequency:\n";
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
