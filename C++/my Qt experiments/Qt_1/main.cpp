#include <QtWidgets/QApplication>
#include "myclass.h"

int main (int argc, char** argv)
{
    QApplication app(argc, argv);

    MyClass *parent = new MyClass("Parent", NULL);
    MyClass *a = new MyClass("A", parent),
             *b = new MyClass("B", parent);

    MyClass *c = new MyClass("C");

    c->setParent(a);

    delete parent;

    return app.exec();
}
