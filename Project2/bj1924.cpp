#include <iostream>
#include <string>
using namespace std;

int main()
{
    
    int month_of_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int month, day, day_of_the_week, days = 0;
    cin >> month >> day;

    if (month == 1) days = day; 
    else {
        for(int i = 0; i < month-1; i++){
           days += month_of_days[i];
        }
        days += day;
    }
    day_of_the_week = days % 7;
    switch(day_of_the_week) {
    case 0: cout << "SUN"; break;
    case 1: cout << "MON"; break;
    case 2: cout << "TUE"; break;
    case 3: cout << "WED"; break;
    case 4: cout << "THU"; break;
    case 5: cout << "FRI"; break;
    case 6: cout << "SAT"; break;
    }
}