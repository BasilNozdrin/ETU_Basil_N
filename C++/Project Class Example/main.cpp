#include <iostream>
#include <string>
#incluse "meClass.h"

using namespace std;

int main()
{
    cout << "Program started...\n";
    myClass a(1);
    cout << "myClass a(1); done...\n";
    a.showVar();
    cout << "a.showVar(); done...\n";
    return 0;
}
