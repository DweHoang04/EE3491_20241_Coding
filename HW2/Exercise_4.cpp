#include <iostream>

using namespace std;

string starReplace(string str)
{
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        if (str[i] != ' ')
            str[i] = '*';
    }

    return str;
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    cout << "Replaced string: " << starReplace(str) << endl;

    return 0;
}