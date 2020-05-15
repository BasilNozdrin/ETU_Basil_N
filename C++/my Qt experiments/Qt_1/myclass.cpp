#include "myclass.h"
#include <QDebug>

MyClass::MyClass(const QString &name, QObject *parent) :
    QObject(parent), m_name(name)
{

}

MyClass::~MyClass()
{
    qDebug() << "Object" << this->m_name << " is being deleted";
}
