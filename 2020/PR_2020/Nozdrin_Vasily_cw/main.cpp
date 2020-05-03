#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "counter.h"


int main(int c, char **v)
{
    QApplication app(c, v);
    QPushButton but("Bye bitch", NULL);
    but.show();
    QObject::connect(&but, SIGNAL(clicked()), qApp, SLOT(quit()));

    Counter a, b;

    QObject::connect(&a, SIGNAL(valueChanged(int, int)),
                     &a, SLOT(print()));

    QObject::connect(&b, SIGNAL(valueChanged(int, int)),
                     &b, SLOT(print()));

    QObject::connect(&a, SIGNAL(valueChanged(int, int)),
                     &b, SLOT(setValue(int)));


    b.setValue(20);
    a.setValue(10);

    return app.exec();
}
