#include <iostream>

using namespace std;

int strToInt(string str) {
    bool isNegative = false;
    int num = 0;
    int startIndex = 0;

    if (str[0] == '-') {
        isNegative = true;
        startIndex = 1;
    }

    for (int i = startIndex; i < str.length(); i++) {
        if (str[i] < '0' || str[i] > '9') {
            cout << "Inappropriate string" << endl;
            return 0;
        }
        else {
            num = num * 10 + (str[i] - '0');
        }
    }

    if (isNegative) {
        num *= -1;
    }

    return num;
}

int main() {
    string input;
    int output;
    cout << "Enter a number string: ";
    cin >> input;
    cout << "String after being converted to integer: " << strToInt(input) << endl;

    return 0;
}