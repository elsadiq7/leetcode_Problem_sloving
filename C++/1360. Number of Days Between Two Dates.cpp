#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int days1 = fdata(date1);
        int days2 = fdata(date2);
        return abs(days1 - days2); // Ensure positive difference
    }

    unsigned int fdata(string date) {   
        unsigned int sum = 0;
        int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        // Count total days from 1900 to (year-1)
        for (int i = 1900; i < year; i++) {  
            if (check_leap(i))
                sum += 366;
            else 
                sum += 365;
        }

        // Count days for full months before 'month'
        for (int i = 0; i < month - 1; i++) {  // Fix: Use i-1 as index
            sum += days_in_month[i];
        }

        // Add extra day if the current year is a leap year and month > 2 (past February)
        if (month > 2 && check_leap(year)) {
            sum += 1;
        }

        // Add remaining days in the current month
        sum += day;

        return sum;
    }

    bool check_leap(int year) {
        if (year % 400 == 0)
            return true;
        else if (year % 100 == 0)
            return false;
        else if (year % 4 == 0)  
            return true;
        return false;
    }
};
