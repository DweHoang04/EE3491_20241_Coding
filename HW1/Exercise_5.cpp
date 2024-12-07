#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double convertToBytesFactor(string unit) {
    if (unit == "B")
        return 1;
    else if (unit == "KB") 
        return pow(1024, 1); 
    else if (unit == "MB") 
        return pow(1024, 2); 
    else if (unit == "GB") 
        return pow(1024, 3); 
    else if (unit == "TB") 
        return pow(1024, 4); 
    else if (unit == "PB") 
        return pow(1024, 5); 
    else if (unit == "EB") 
        return pow(1024, 6); 
    else if (unit == "ZB") 
        return pow(1024, 7); 
    else
        return 1;
}

int main() {
    string input;
    cout << "Enter the capacity of the disk (e.g: 40GB): ";
    cin >> input;

    string numberPart = input.substr(0, input.length() - 2); 
    string unitPart = input.substr(input.length() - 2);    

    double labelCapacity = stod(numberPart);
    double manufacturerBytes = labelCapacity * pow(1000, 
    (unitPart == "KB" ? 1 : unitPart == "MB" ? 2 : unitPart == "GB" ? 3 : 
    unitPart == "TB" ? 4 : unitPart == "PB" ? 5 : unitPart == "EB" ? 6 : 
    unitPart == "ZB" ? 7 : 0));
    double actualCapacity = manufacturerBytes / convertToBytesFactor(unitPart);

    cout << "Actual capacity of the disk is: " << actualCapacity << unitPart << endl;

    return 0;
}
