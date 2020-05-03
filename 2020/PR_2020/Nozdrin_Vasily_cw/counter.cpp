#include "counter.h"
#include <QDebug>

Counter::Counter(QObject *parent) : QObject(parent)
{
    m_value = 0;
}

void Counter::print () const
{
    qDebug() << "value = " << this->m_value;
}

void Counter::setValue(int value)
{
    if (m_value == value)
        return;

    int oldValue = this->m_value;
    this->m_value = value;

    emit valueChanged(oldValue, this->m_value);
}
