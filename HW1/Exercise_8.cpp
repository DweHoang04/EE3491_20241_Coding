#include <iostream>

using namespace std;

int main() {
    double velocity, minTemp, maxTemp;
    cout << "Enter minimum temperature in Celsius: ";
    cin >> minTemp;
    cout << "Enter maximum temperature in Celsius: ";
    cin >> maxTemp;
    for (int i = minTemp; i <= maxTemp; i++) {
        velocity = 331.3 + 0.61*i;
        cout << "At " << i << " degrees Celsius the velocity of sound is " << velocity << " m/s" << endl;
    }

    return 0;
}