#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char alphabetLower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

char alphabetUpper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// Find the position of the character in the alphabet (case sensitive)
int alphabetPosition(char ch) {
    if (islower(ch)) {
        for (int i = 0; i < sizeof(alphabetLower); i++) {
        if (ch == alphabetLower[i])
            return i;
        }
    } else if (isupper(ch)) {
        for (int i = 0; i < sizeof(alphabetUpper); i++) {
        if (ch == alphabetUpper[i])
            return i;
        }
    }

    return -1;
}

// Encode the input message
void encoderShiftN(string &str, int n) {
    n = (n % 26 + 26) % 26; // Normalize n to appropriate position
    int length = str.length();

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            int pos = alphabetPosition(str[i]);
            if (isupper(str[i])) {
                str[i] = alphabetUpper[(pos + n) % 26];
            } else if (islower(str[i])) {
                str[i] = alphabetLower[(pos + n) % 26];
            } 
        }
    }
}

// Decode the encoded message
void decoderShiftN(string &str, int n) {
    n = (n % 26 + 26) % 26;
    int length = str.length();

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            int pos = alphabetPosition(str[i]);
            if (isupper(str[i])) {
                str[i] = alphabetUpper[(pos - n + 26) % 26];
            } else if (islower(str[i])) {
                str[i] = alphabetLower[(pos - n + 26) % 26];
            } 
        }
    }
}

int main() {
    string message;
    int n;

    cout << "Enter your message: ";
    getline(cin, message);
    cout << "Enter number of shifted characters: ";
    cin >> n;

    encoderShiftN(message, n);
    cout << "Encoded message: " << message << endl;

    decoderShiftN(message, n);
    cout << "Decoded message: " << message;

   return 0;
}