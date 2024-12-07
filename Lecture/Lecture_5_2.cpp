#include <iostream>

using namespace std;

int main() {
    union Endian {
        int i;
        char byte[4];
    }; 

    union endian data;
    data.i = 0x01020304;

    if (data.byte[0] == 0x01) {
        cout << "The system is big-endian" << endl;
    }
    else {
        if (data.byte[3] == 0x01) 
            cout << "The system is small-endian" << endl;
    }
    // Xem vi du trong slide

    return 0;
}