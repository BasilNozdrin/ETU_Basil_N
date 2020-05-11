#ifndef DIALOGCIRCLE_H
#define DIALOGCIRCLE_H

#include "mypng.h"
#include "selectcolorbutton.h"

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTimerEvent>

class DialogCircle : public QDialog
{
    Q_OBJECT
    QLabel *m_lblX1;
    QLabel *m_lblY1;
    QLabel *m_lblX2;
    QLabel *m_lblY2;
    QLabel *m_lblThikness;
    QLabel *m_lblMainColor;
    QLabel *m_lblLineColor;

    QLineEdit *m_valueX1;
    QLineEdit *m_valueY1;
    QLineEdit *m_valueX2;
    QLineEdit *m_valueY2;
    QLineEdit *m_valueThikness;

    SelectColorButton *m_btnMainColor;
    SelectColorButton *m_btnLineColor;

    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;

    QColor *m_valueMainColor;
    QColor *m_valueLineColor;

public:
    explicit DialogCircle(QWidget *parent = nullptr);

signals:
    void drawACircle();

public slots:
    void chooseMainColor();
    void chooseLineColor();
    void setMainColor(QColor &color);
    void setLineColor(QColor &color);

};


#endif // DIALOGCIRCLE_H
