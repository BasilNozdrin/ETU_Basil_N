#ifndef PERSON_H
#define PERSON_H
#include "birthday.h"


class person
{
    public:
        person(string n, birthday b);
        void printInfo();
        void printInfo(int a);

    protected:

    private:
        string name;
        birthday bd;
};

#endif // PERSON_H
