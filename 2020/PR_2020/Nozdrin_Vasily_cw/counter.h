#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
public:
    int m_value;
    explicit Counter(QObject *parent = nullptr);

signals:
    void valueChanged(int oldValue, int newValue);

public slots:
    void setValue (int value);
    void print () const;
};

#endif // COUNTER_H
