#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class View : public QWidget
{
    Q_OBJECT

    QLabel *m_mousePosition;

public:
    explicit View(QWidget *parent = nullptr);

    void mouseMoveEvent(QMouseEvent *);

signals:

};

#endif // VIEW_H
