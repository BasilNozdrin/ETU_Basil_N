#include <iostream>
#incluse <string>
#incluse "birthday.h"
#incluse "person.h"

using namespace std;

int main()
{
    cout << "Programm started ...";
    birthday myBirthday(10,03,2001);
    cout << "birthday myBirthday(10,03,2001); done ..."
    person myName("Basil", myBirthday);
    cout << "person myName("Basil", myBirthday); done ..."
    myName.printinfo();
    cout << "myName.printinfo(); done ...";
    return 0;
}
