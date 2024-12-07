#include <iostream>

using namespace std;

bool isPalindrome(string str) 
{
    int length = str.length();
    int mid = length / 2;
    for (int i = 0; i < mid; i++) /* Check if the given string is Palindrome or not */
    {
        if (str[i] != str[length - i - 1])
            return false;
    }

    return true;
}

int main()
{
    string str;
    cout << "Enter your string: ";
    getline(cin, str);

    bool check = isPalindrome(str);
    if (check)
        cout << "Your string is Palindrome." << endl;
    else
        cout << "Your string is not Palindrome." << endl;

    return 0;
}