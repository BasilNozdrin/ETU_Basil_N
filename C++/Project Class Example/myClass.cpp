#include <iostream>
#include "myClass.h"

using namespace std;

myClass::myClass(int x)  //constructor
{
    var = x;
};

void myClass::showVar()
{
    std::cout << var << std::endl;
}
;
