#include <iostream>

using namespace std;

const double G = 6.67/100000000000;

int main() {
    double force, mass_1, mass_2, distance;
    bool check;

    do {
        cout << "Enter the mass of object 1 in kilogram: ";
        cin >> mass_1;

        cout << "Enter the mass of object 2 in kilogram: ";
        cin >> mass_2;

        cout << "Enter the distance between two objects in meter: ";
        cin >> distance;

        if (cin.fail()) {
            cout << "Invalid input. Please enter numbers only!" << endl;
            cin.clear();  
            cin.ignore(1000, '\n');  
            check = true;
            continue;
        }
    } while (check)

    force = G*(mass_1*mass_2)/(distance*distance);
    cout << "The gravitational force between the two objects: " << force << endl;

    return 0;
}