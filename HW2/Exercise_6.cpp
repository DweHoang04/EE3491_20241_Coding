#include <iostream>

using namespace std;

void characterFrequency(const string &str)
{
    // Array to store character frequency
    int frequency[256] = {0};

    // Update frequency of each characters in the string
    for (char ch : str)
        if (ch != ' ')
            frequency[(char) ch]++;
    
    // Print the characters and their frequency
    cout << "Characters' Frequency:" << endl;
    for (int i = 0; i < 256; i++)
    {
        if (frequency[i] > 0)
            cout << "Character: " << (char)i << " | Frequency: " <<  frequency[i] << endl;
    }
}

int main() 
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    characterFrequency(str);

    return 0;
}
