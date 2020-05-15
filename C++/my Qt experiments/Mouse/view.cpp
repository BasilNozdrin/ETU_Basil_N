#include "view.h"

#include <QVBoxLayout>
#include <QMouseEvent>

View::View(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout());
    m_mousePosition = new QLabel("Position: ", this);
    layout()->addWidget(m_mousePosition);

}

void View::mouseMoveEvent(QMouseEvent *me)
{
    QPoint pos = me->pos();

    m_mousePosition->setText("position: x = " +
                             QString::number(pos.x()) +
                             ", y = " +
                             QString::number(pos.y()));
}
