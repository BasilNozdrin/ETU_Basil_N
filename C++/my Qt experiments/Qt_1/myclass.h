#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT

    QString m_name;

public:
    explicit MyClass(const QString &name, QObject *parent = nullptr);
    ~MyClass();

signals:

};

#endif // MYCLASS_H
