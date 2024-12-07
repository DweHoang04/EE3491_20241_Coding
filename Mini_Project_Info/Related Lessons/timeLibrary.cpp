#include <iostream>
#include <unistd.h> //Use sleep() function
#include <time.h>

using namespace std;

int main(void)
{
    time_t now = time(NULL); // Return the current time in seconds since midnight January 1st 1970
    
    sleep(2);

    time_t two_secs = time(NULL); 

    double diff = difftime(two_secs, now); // Calculate the difference between two time_t values

    char *string_now = ctime(&now); // Convert time_t to string
    struct tm *gm_time = gmtime(&now); // Convert time_t to tm struct
    cout << "GM time: " << gm_time->tm_hour << ":" << gm_time->tm_min << ":" << gm_time->tm_sec << endl; // Print the time in GMT

    struct tm *cur_time = localtime(&now); // Convert time_t to tm struct
    cout << "Local time: " << cur_time->tm_hour << ":" << cur_time->tm_min << ":" << cur_time->tm_sec << endl; // Print the time in local time

    char *other_string = asctime(cur_time); // Customize the string format

    // Example
    cur_time->tm_hour = cur_time->tm_hour + 1; // Add one hour to the current time
    time_t new_time = mktime(cur_time); // Take the tm struct and convert it back to time_t
    cout << "New time: " << ctime(&new_time) << endl; // Print the new time

    return 0;
}