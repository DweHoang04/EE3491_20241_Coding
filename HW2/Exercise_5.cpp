#include <iostream>

using namespace std;

void removeExtraSpaces(char* str)
{
    int i = 0, j = 0;

    // Ignore leading spaces
    while (str[i] == ' ')
        i++;
    
    // Remove unecessary spaces between words
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            str[j++] = str[i];
            i++;
        }
        else if (i > 0 && str[i - 1] != ' ')
        {
            str[j++] = ' ';
            i++;
        }
        else
        {
            i++;
        }
    }
    if (j > 0 && str[j - 1] == ' ')
        str[j - 1] = '\0';
    else
        str[j] = '\0';
}

int main()
{
    int max_size;
    cout << "Enter your maximum string size: ";
    cin >> max_size;

    // Clear the newline left in the input buffer by 'cin >> max_size'
    cin.ignore();

    // Dynamically allocate the character array
    char *str = new char[max_size];

    cout << "Enter your string: ";
    cin.getline(str, max_size);

    removeExtraSpaces(str);

    cout << "String after removing extra spaces: \"" << str << "\"" << endl;

    // Free dynamically allocated array
    delete[] str;

    return 0;
}