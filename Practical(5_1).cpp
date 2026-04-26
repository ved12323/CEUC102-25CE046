#include <iostream>
#include <string>
using namespace std;

class WordFrequency {
    string paragraph;
    string words[100];
    int freq[100];
    int n;

public:
    WordFrequency() {
        n = 0;
        for (int i = 0; i < 100; i++) {
            freq[i] = 0;
        }
    }

    void getInput() {
        cout << "Enter paragraph: ";
        getline(cin, paragraph);
    }

    void process() {
        string temp = "";

        for (int i = 0; i <= paragraph.length(); i++) {
            char ch = paragraph[i];
  
            if (ch >= 'A' && ch <= 'Z') {
                ch = ch + 32;
            }

            if (ch >= 'a' && ch <= 'z') {
                temp = temp + ch;
            } else {
                if (temp != "") {
                    words[n] = temp;
                    n++;
                    temp = "";
                }
            }
        }
    }

    void countWords() {
        for (int i = 0; i < n; i++) {
            if (freq[i] == -1) continue;

            int count = 1;

            for (int j = i + 1; j < n; j++) {
                if (words[i] == words[j]) {
                    count++;
                    freq[j] = -1;
                }
            }

            freq[i] = count;
        }
    }

    void display() {
        cout << "\nWord Frequency:\n";
        for (int i = 0; i < n; i++) {
            if (freq[i] != -1) {
                cout << words[i] << " : " << freq[i] << endl;
            }
        }
    }
};

int main() {
    WordFrequency obj;

    obj.getInput();
    obj.process();
    obj.countWords();
    obj.display();

    return 0;
}
