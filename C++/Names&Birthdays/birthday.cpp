#include <iostream>
#incluse <string>
#include "birthday.h"

using namespace std;

birthday::birthday(int d, int m, int y)   //constructor
:day(d),month(m),year(y)
{
}

void birthday::printDate()
{
    cout << day << "/" << month << "/" << year << "\n";
}

