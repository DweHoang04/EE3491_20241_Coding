#include <iostream>

using namespace std;

string reverseString(string str) {
    int end = str.size();
    string reversed;

    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ' ' || i == 0) {
            int start = (i == 0) ? i : i + 1;
            reversed += str.substr(start, end - start);
            
            if (i != 0) {
                reversed += ' ';
            }

            end = i;
        }
    }
    return reversed;
}

int main() {
    string str;
    cout << "Enter your string: ";
    getline(cin, str);
    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << endl;

    return 0;
}