#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void classifyAndCount(string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for reading\n";
        return;
    }

    int gradeCount[5] = {0}; // Store the count of each grade
    string line;

    // Skip the header file
    if (getline(file, line))
        cout << "Reading data from file...\n";
    
    while (getline(file, line)) {
        size_t lastComa = line.rfind(',');
        double point = stod(line.substr(lastComa + 1));
        
        if (point > 8.0 && point <= 10)
            gradeCount[0]++;
        else if (point > 6.0 && point <= 8)
            gradeCount[1]++;
        else if (point > 4.0 && point <= 6.0)
            gradeCount[2]++;
        else if (point > 2.0 && point <= 4.0)
            gradeCount[3]++;
        else if (point >= 0 && point <= 2.0)
            gradeCount[4]++; 
    }

    file.close();

    cout << "Grade Classification:\n";
    cout << "A: " << gradeCount[0] << endl;
    cout << "B: " << gradeCount[1] << endl;
    cout << "C: " << gradeCount[2] << endl;
    cout << "D: " << gradeCount[3] << endl;
    cout << "F: " << gradeCount[4] << endl;
}

int main() {
    string filename = "ee3491.csv";
    classifyAndCount(filename);

    return 0;
}