#include <iostream>
#include <string>

using namespace std;

struct Zodiac {
    string sign;
    int startDay, startMonth;
    int endDay, endMonth;
};

const Zodiac zodiacSigns[] = {
    {"Capricorn", 22, 12, 19, 1},
    {"Aquarius", 20, 1, 18, 2},
    {"Pisces", 19, 2, 20, 3},
    {"Aries", 21, 3, 19, 4},
    {"Taurus", 20, 4, 20, 5},
    {"Gemini", 21, 5, 20, 6},
    {"Cancer", 21, 6, 22, 7},
    {"Leo", 23, 7, 22, 8},
    {"Virgo", 23, 8, 22, 9},
    {"Libra", 23, 9, 22, 10},
    {"Scorpio", 23, 10, 21, 11},
    {"Sagittarius", 22, 11, 21, 12}
};

const int NUM_SIGNS = 12;

bool isValidDate(int day, int month) {
    if (month < 1 || month > 12) return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day < 1 || day > daysInMonth[month - 1]) {
        return false;
    }
    
    return true;
}

string getZodiacSign(int day, int month, bool& isCusp) {
    isCusp = false;

    for (int i = 0; i < NUM_SIGNS; ++i) {
        const Zodiac& mySign = zodiacSigns[i];
        if ((month == mySign.startMonth && day >= mySign.startDay) ||
            (month == mySign.endMonth && day <= mySign.endDay)) {
            if ((month == mySign.startMonth && day - mySign.startDay < 3) ||
                (month == mySign.endMonth && mySign.endDay - day < 3)) {
                isCusp = true;
            }

            return mySign.sign;
        }
    }

    return "Unknown"; 
}

string getNeighborZodiacSign(int day, int month, const string& currentSign) {
    for (int i = 0; i < NUM_SIGNS; i++) {
        if (zodiacSigns[i].sign == currentSign) {
            if (month == zodiacSigns[i].startMonth && day - zodiacSigns[i].startDay < 3) {
                int prevIndex = (i - 1 + NUM_SIGNS) % NUM_SIGNS;
                return zodiacSigns[prevIndex].sign;
            } else if (month == zodiacSigns[i].endMonth && zodiacSigns[i].endDay - day < 3) {
                int nextIndex = (i + 1) % NUM_SIGNS;
                return zodiacSigns[nextIndex].sign;
            }
        }
    }
    return "";
}

int main() {
    int day, month;
    char choice;

    do {
        cout << "Enter your birth day (1-31): ";
        cin >> day;
        cout << "Enter your birth month (1-12): ";
        cin >> month;

        if (!isValidDate(day, month)) {
            cout << "Invalid date! Please try again." << endl;
            cout << "Enter your birth day (1-31): ";
            cin >> day;
            cout << "Enter your birth month (1-12): ";
            cin >> month;
        }

        bool isCusp;
        string zodiacSign = getZodiacSign(day, month, isCusp);

        cout << "Your zodiac sign is: " << zodiacSign << endl;

        if (isCusp) {
            string neighborSign = getNeighborZodiacSign(day, month, zodiacSign);
            cout << "Your birth date is on the cusp! It is close to " << neighborSign << " signs." << endl;
        }

        cout << "Do you want to enter another birth date? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}