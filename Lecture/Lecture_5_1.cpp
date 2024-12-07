// Poinnter & Array

// Reference 

/*
int main() {
    double d = 3.14;
    double& r = d;
    double *p = &d, *pr = &r;

    r = 2.17;

    return 0;
}
*/

// Typedef

// Definition: Create a new name for an available type, 
// it does not define a new type

// User-defined data type

/*
- struct
- union
- class
*/

#include <iostream>

using namespace std;

struct Time {
    int hour; 
    int minute; 
    int second;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[32];
    Date birthday;
    int student_id;
}; // Kích thước bằng tổng kích thước của các dữ liệu

union Student {
    char name[32];
    Date birthday;
    int student_id;
} Student; 
// Kích thước bằng kích thước của kiểu dữ liệu lớn nhất

int main() {
    struct Time classtime = {9,20};
    struct Date schooDay = {15,10,1956}; 
    // Chỉ khai báo lúc đầu, không gán giá trị như các biến thông thường
    struct Student a = {"AlanTuring",{1,1,1970},1};
    union Student a = {"AlanTuring"}

    schooDay.year = 2024;
    a.birthday.year = 2004;

    cout << sizeof(Student);

    Student* pStudent = &a;
    char* pName = a.name;
    struct Date* pDate = &a.birthday;
    int* pID = &a.student_id;

    struct Date publicHoliday[] = {{30,4,1975},{2,9,1945}};
    struct Date nationlDay = publicHolidays[1];
    // Dù khai báo các biến trong kiểu struct giống nhau nhưng 
    // máy vẫn sẽ coi hai struct khác nhau là hai kiểu dữ liệu 
    // khác nhau.

    struct Student* plist;

    return 0; 

    // if else; switch case
}