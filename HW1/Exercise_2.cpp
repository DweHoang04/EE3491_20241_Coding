#include <iostream>
#include <cmath>

using namespace std;

bool hasDecimalPart(double num) {
    return fabs(num - static_cast<int>(num)) > 0.0;
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    double a, b, c, num;
    int digitB, digitC;
    bool check;

    do {
        cout << "Enter the digits: ";
        cin >> a >> b >> c;

        if (cin.fail()) {
            cout << "Invalid input. Please enter numbers only!" << endl;
            cin.clear();  
            cin.ignore(1000, '\n');  
            check = true;
            continue;
        }

        if (hasDecimalPart(a) || hasDecimalPart(b) || hasDecimalPart(c)) {
            cout << "Please enter integers only!" << endl;
            check = true;
        } else {
            check = false; 
        }

    } while (check);
    
    digitC = countDigits(c);
    b = b * pow(10, digitC);
    digitB = countDigits(b);
    num = a * pow(10, digitB) + b + c;
    
    cout.width(10);
    cout << "The number is: " << num << endl;

    return 0;
}