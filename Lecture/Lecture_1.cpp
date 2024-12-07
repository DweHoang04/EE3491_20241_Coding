/*

Chapter 1: Introduction
1. Course Description
+) Aim and scopes
- This course provides fundamentals of programming techniques,
implemented with C++ programming language.
+ Structure programming
+ Object-oriented programming
+ Real-time programming and typical data structures
+ Generic programming
- You will also learn the essential knowledge, including:
+ Memory management, pointers, preprcessor macros;
+ How to find bugs;...
+) Evaluations
- Progres assessment: 30%
+ Weekly quizzes (Progress scores): Maybe on class or HW.
+ Mini project: Up to 3 bonus points.
+ Midterm exam (written)
- Final exam: 70%
* Midterm and final exams:
- Written exams
- Duration: 60 - 90 minutes
- Includes:
+ Theoretical questions
+ Programming exercises, etc

2. Computer Hardware
3. Computer Software
- Types of programm:
+ System software: Operating system, device drivers, utilities
+ Application software: Word processors, spreadsheets, games, etc

*/

#include <iostream>
#include <cmath> // For abs() function

using namespace std;

double calculateExponential(double x, double epsilon) {
    double term = 1;   // The first term in the Taylor series is 1
    double result = 1; // The sum starts at 1 (first term)
    int k = 1;         // Start from the first term after 1

    // Continue adding terms until the term is smaller than epsilon
    while (abs(term) >= epsilon) {
        term = term * (x / k); // Calculate the next term: x^k / k!
        result += term;        // Add the term to the result
        k++;
    }

    return result;
}

int main() {
    double x, epsilon;

    // Input the value of x and the precision epsilon
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the precision epsilon: ";
    cin >> epsilon;

    // Calculate e^x
    double result = calculateExponential(x, epsilon);

    // Output the result
    cout << "The approximate value of e^" << x << " is: " << result << endl;

    return 0;
}