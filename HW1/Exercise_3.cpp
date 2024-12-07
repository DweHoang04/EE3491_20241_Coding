#include <iostream>

using namespace std;

int main() {
    int num, invertedNum = 0;
    cout << "Enter a number: ";
    cin >> num;
    while (num) {
        invertedNum = invertedNum * 10 + num % 10;
        num /= 10;
    }
    cout << "The inverted number is: " << invertedNum << endl;
    
    return 0;
}