#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

void toUpperCase(string& str) 
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return toupper(c); });
}

// Convert 12-hour format to 24-hour format
void convertTo24Hour(int hour, int minute, string &meridiem) 
{
    toUpperCase(meridiem);
    
    if (meridiem == "PM" && hour != 12) {
        hour += 12;
    } else if (meridiem == "AM" && hour == 12) {
        hour = 0;
    }

    cout << "24-hour format: " 
         << setw(2) << setfill('0') << hour << ':' 
         << setw(2) << setfill('0') << minute << endl;
}

// Convert 24-hour format to 12-hour format
void convertTo12Hour(int hour, int minute) 
{
    string meridiem = (hour >= 12) ? "PM" : "AM";

    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }

    cout << "12-hour format: "
         << setw(2) << setfill('0') << hour << ':' 
         << setw(2) << setfill('0') << minute << meridiem << endl;
}


int main() 
{
    int hour, minute, type;
    string meridiem, seperator;

    cout << "Choose your input time format (12/24): ";
    cin >> type;

    if (type == 12)
    {
        cout << "Type your time in 12-hour format: ";
        cin >> hour >> seperator >> minute >> meridiem;

        convertTo24Hour(hour, minute, meridiem);
    } 
    else if (type == 24) 
    {
        cout << "Type your time in 24-hour format: ";
        cin >> hour >> seperator >> minute;

        convertTo12Hour(hour, minute);
    }
    else 
    {
        cout << "Invalid Input.";
    }
    
    return 0;
}