#include <iostream>

using namespace std;

int main(int argc, char* argv[])
/* argc (argument count): Number of argument that the program received, including program name */
// argc = 1 means there is only one argument: Name of the program
// argc >= 2 means there are other arguments

/* argv (argument vector): Char type pointer, whose elements point to a string contain an argument type form the command line */
// argv[0] is the name of the program
// argv[1] to argv[argc - 1] are arguments typed by user from the command line
{
    cout << "Number of arguments: " << argc << endl;

    for (int i = 0; i < argc; i++)
    {
        cout << "Arguments " << i << ": " << argv[i] << endl;
    }

    return 0;
}