#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void writeStudentInfo(fstream &file, int studentIndex) {
    string studentID, name;
    double point;

    cout << "\nEnter student " << studentIndex << "'s ID: ";
        cin >> studentID;
        cin.ignore(); // Clear the input buffer after reading the number of student
        cout << "Enter student " << studentIndex << "'s name: ";
        getline(cin, name);
        cout << "Enter student " << studentIndex << "'s point: ";
        cin >> point;
        while (point < 0 || point > 10.0) {
            cout << "Invalid point. Please type again (Range: 0-10): ";
            cin >> point;
        }

        file << studentID << "," << name << "," 
               << fixed << setprecision(1) << point << "\n";
}

int main() {
    fstream ee3491;
    int number_of_student;

    cout << "Enter number of student in your class: ";
    cin >> number_of_student;

    ee3491.open("ee3491.csv",ios::out);
    if (!ee3491.is_open()) {
        cerr << "Error: Could not open file for writing\n";
        return 1;
    }

    ee3491 << "SID,Name,Point\n";

    cout << "Example output: 20221234,Nguyen Van A,9.0";

    for (int i = 1; i <= number_of_student; i++) {
        writeStudentInfo(ee3491, i);
    }

    ee3491.close();
    cout << "Data written to ee3491.csv\n";

    return 0;
}