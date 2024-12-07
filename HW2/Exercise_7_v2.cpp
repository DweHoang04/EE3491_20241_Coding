#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Capitalize all characters in the given string
void toUpperCase(string& str) 
{
    transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return toupper(c); });
}

// Check whether the input time is in 24-hour format or 12-hour format
bool formatCheck(const string& str) 
{
    size_t pos1 = str.find("AM");
    size_t pos2 = str.find("PM");

    return (pos1 != string::npos || pos2 != string::npos);
}

// Extract hour and minute from the input string
void numberExtract(const string& str, string& hour, string& minute) 
{
    int length = str.length();

    for (int i = 0; i < length; i++) {
        if (isdigit(str[i])) {
            hour = str.substr(i, 2);
            minute = str.substr(i + 3, 2);
            break;
        }
    }
}

// Convert 12-hour format to 24-hour format
void convertTo24Hour(int hour, int minute, const string& str) 
{
    if (str.find("PM") != string::npos && hour != 12) {
        hour += 12;
    } else if (str.find("AM") != string::npos && hour == 12) {
        hour = 0;
    }

    cout << "24-hour format: " << setw(2) << setfill('0') << hour << ':' 
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

    cout << "12-hour format: " << setw(2) << setfill('0') << hour << ':' 
         << setw(2) << setfill('0') << minute << meridiem << endl;
}

bool isValidTime(string& time, string& hour, string& minute) 
{
    numberExtract(time, hour, minute);

    // Check if extracted hour and minute are valid numbers
    if (hour.empty() || minute.empty() || !all_of(hour.begin(), hour.end(), ::isdigit) || !all_of(minute.begin(), minute.end(), ::isdigit)) 
        return false;


    int hourNum = stoi(hour);
    int minuteNum = stoi(minute);

    // Check if the hour and minute are appropriate for each type of time format
    if (formatCheck(time))
    {
        if (hourNum < 0 || hourNum > 12 || minuteNum < 0 || minuteNum > 59)
            return false;
    }
    else if (hourNum < 0 || hourNum > 23 || minuteNum < 0 || minuteNum > 59)
        return false;

    return true;
}

int main() 
{
    string time, hour, minute;
    cout << "Enter your time in 24-hour format or 12-hour format (e.g: 12:34 or 12:34 AM): ";
    getline(cin, time);

    toUpperCase(time);

    while (!isValidTime(time, hour, minute)) {
        cout << "Invalid time input. Please type again!" << endl;
        cout << "Enter your time in 24-hour format or 12-hour format (e.g: 12:34 or 12:34 AM): ";
        getline(cin, time);
        toUpperCase(time);
    }

    int hour_num = stoi(hour);
    int minute_num = stoi(minute);

    if (formatCheck(time)) {
        convertTo24Hour(hour_num, minute_num, time);
    } else {
        convertTo12Hour(hour_num, minute_num);
    }

    return 0;
}