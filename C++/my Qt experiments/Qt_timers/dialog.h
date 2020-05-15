#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimerEvent>


class Dialog : public QDialog
{
    Q_OBJECT

    QLabel *m_lblTimer1;
    QLabel *m_lblTimer2;

    QLineEdit *m_valueTimer1;
    QLineEdit *m_valueTimer2;
    QLineEdit *m_inputValue;

    QPushButton *m_btnStart;
    QPushButton *m_btnStop;

public:
    explicit Dialog(QWidget *parent = 0);
    void timerEvent(QTimerEvent *);

public slots:
    void startPressed();
};

#endif // DIALOG_H
