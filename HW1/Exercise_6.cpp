#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a, b, c, x1, x2, delta;
    cout << "Enter the coefficient of the equation: ";
    cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0) {
            x1 = -c/b;
            cout << "The equation has one solution: x = " << x1 << endl;
        } else {
            if (c == 0) 
                cout << "The equation has infinity solutions.";
            else
                cout << "The equation has no solution.";
            }
    }
    else {
        delta = b*b - 4*a*c;
        if (delta < 0) {
            cout << "x1 = " << -b/(2*a) << " + i" << sqrt(-delta)/(2*a) << endl;
            cout << "x2 = " << -b/(2*a) << " - i" << sqrt(-delta)/(2*a) << endl;
        } else if (delta == 0)
            cout << "x = " << -b/(2*a);
        else {
            x1 = (-b + sqrt(delta))/(2*a);
            x2 = (-b - sqrt(delta))/(2*a);
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }

    return 0;
    
}