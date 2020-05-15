#include <iostream>
#incluse <string>
#include "person.h"
#include "birthday.h"

using namespace std;

person::person(string n, birthday b): name(n),bd(b)    //constructor
{
}

void person::printinfo()
{
    cout << name << "\n";
    bd.printDate();
}

void person::printinfo(int a)
{
    if (a = 0) then
    {
        cout << name << "\n";
    }
    else
    {
        bd.printDate();
    }

}
