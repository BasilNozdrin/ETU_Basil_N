#include "dialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

Dialog::Dialog(QWidget *)
{
    setLayout(new QVBoxLayout());

    QHBoxLayout *layTimer1 = new QHBoxLayout();
    QHBoxLayout *layTimer2 = new QHBoxLayout();

    m_valueTimer1 = new QLineEdit("0", this);
    m_valueTimer2 = new QLineEdit("0", this);
    layTimer1->addWidget(new QLabel("Timer 1", this));
    layTimer2->addWidget(new QLabel("Timer 2", this));
    layTimer1->addWidget(m_valueTimer1);
    layTimer2->addWidget(m_valueTimer2);

    m_inputValue = new QLineEdit ("1000", this);
    m_btnStart = new QPushButton ("Start", this);
    m_btnStop = new QPushButton ("Stop", this);

    QHBoxLayout *layBtn = new QHBoxLayout ();
    layBtn->addWidget(m_btnStart);
    layBtn->addWidget(m_btnStop);

    layout()->addItem(layTimer1);
    layout()->addItem(layTimer2);
    layout()->addWidget(m_inputValue);
    layout()->addItem(layBtn);

    connect(m_btnStart, SIGNAL(clicked()),
            this, SLOT(startPressed()));
}

void Dialog::timerEvent(QTimerEvent *)
{
    qDebug() << ".";
}

void Dialog::startPressed()
{
    int msec = m_inputValue->text().toInt();
    startTimer(msec);
}
