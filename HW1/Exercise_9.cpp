#include <iostream>

using namespace std;

int main() {
    double x1, x2, y1, y2, m, c;
    cout << "Enter the coordinate x1, y1, x2, y2 respectively: ";
    cin >> x1 >> y1 >> x2 >> y2;
    while ((x2 - x1) == 0) {
        cout << "Please enter valid x1 and x2 coordinates of the line: ";
        cin >> x1 >> x2;
    }
    m = (y2 - y1)/(x2 - x1);
    cout << "The slope of the line is: " << m << endl;
    c = y1 - m*x1;
    if (m == 1)
        cout << "The equation of the line is: y = x + " << c << endl;
    else if (m == -1)
        cout << "The equation of the line is: y = -x + " << c << endl;
    else
        cout << "The equation of the line is: y = " << m << "x + " << c << endl;

    return 0;
}