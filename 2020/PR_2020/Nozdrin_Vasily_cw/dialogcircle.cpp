#include "dialogcircle.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QColorDialog>

#include <QDebug>

DialogCircle::DialogCircle(QWidget *)
{
    setLayout(new QVBoxLayout(this));

    QHBoxLayout *layPoint1 = new QHBoxLayout(this);
    QHBoxLayout *layPoint2 = new QHBoxLayout(this);
    m_valueX1 = new QLineEdit("0", this);
    m_valueY1 = new QLineEdit("0", this);
    layPoint1->addWidget(new QLabel("x_1", this));
    layPoint1->addWidget(m_valueX1);
    layPoint1->addWidget(new QLabel("y_1", this));
    layPoint1->addWidget(m_valueY1);
    m_valueX2 = new QLineEdit("0", this);
    m_valueY2 = new QLineEdit("0", this);
    layPoint2->addWidget(new QLabel("x_2", this));
    layPoint2->addWidget(m_valueX2);
    layPoint2->addWidget(new QLabel("y_2", this));
    layPoint2->addWidget(m_valueY2);

    QHBoxLayout *layProperties = new QHBoxLayout(this);
    m_valueThikness = new QLineEdit("0", this);
    layProperties->addWidget(new QLabel("Line thikness", this));
    layProperties->addWidget(m_valueThikness);
    m_btnMainColor = new SelectColorButton (new QPushButton("...", this));
    m_btnLineColor = new SelectColorButton (new QPushButton("...", this));
    layProperties->addWidget(new QLabel("Choose main color", this));
    layProperties->addWidget(m_btnMainColor);
    layProperties->addWidget(new QLabel("Choose line color", this));
    layProperties->addWidget(m_btnLineColor);

    QHBoxLayout *layBtn = new QHBoxLayout ();
    m_btnOk = new QPushButton ("Ok", this);
    layBtn->addWidget(m_btnOk);
    m_btnCancel = new QPushButton ("Cancel", this);
    layBtn->addWidget(m_btnCancel);

    layout()->addItem(layPoint1);
    layout()->addItem(layPoint2);
    layout()->addItem(layProperties);
    layout()->addItem(layBtn);

    connect(m_btnCancel, SIGNAL(clicked()),
            this, SLOT(close()));

    connect(m_btnMainColor, SIGNAL(clicked()),
            this, SLOT(chooseMainColor()));
    connect(m_btnLineColor, SIGNAL(clicked()),
            this, SLOT(chooseLineColor()));
}

void DialogCircle::chooseMainColor()
{
    QColorDialog colorPicker;
    colorPicker.setOption(QColorDialog::ShowAlphaChannel);
    connect(&colorPicker, SIGNAL(colorSelected(const QColor &color)),
            this, SLOT(setMainColor(QColor &color)));
    colorPicker.exec();
}

void DialogCircle::chooseLineColor()
{
    QColorDialog colorPicker;
    colorPicker.setOption(QColorDialog::ShowAlphaChannel);
    connect(&colorPicker, SIGNAL(colorSelected(const QColor &color)),
            this, SLOT(setLineColor(QColor &color)));
    colorPicker.exec();
}

void DialogCircle::setMainColor(QColor &color)
{
    this->m_valueMainColor = new QColor;
    *m_valueMainColor = color;
}

void DialogCircle::setLineColor(QColor &color)
{
    this->m_valueLineColor = new QColor;
    *m_valueLineColor = color;
    qDebug() << "line color changed to " << color << "\n";
}

