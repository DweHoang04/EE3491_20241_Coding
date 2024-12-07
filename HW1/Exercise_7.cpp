#include <iostream>

using namespace std;

int main() {
    float h;
    cout << "Parking Time: ";
    cin >> h;
    int F;
    while (h < 0 || h > 24) {
        cout << "Please enter valid number of time in a day: ";
        cin >> h;
    }
    if (h >= 0 & h <= 3) {
        cout << "Total cost: " << 5 << "$";
    } else if (h <= 9) {
        F = 6*((int) h + 1);
        cout << "Total cost: " << F << "$";
    } else 
        cout << "Total cost: " << 60 << "$$";

    return 0;
}