#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QScreen>
#include "dialogcircle.h"
#include "mypng.h"

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool loadFile(const QString &);


private slots:
    void open();
    void saveAs();
    void m_drawCircle();
    void m_callDrawCircle();
    void m_rgbaFilter();
    void m_splitImage();
    void m_drawSquareWithDiagonals();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();

private:
    void createActions();
    void createMenus();
    void updateActions();
    bool saveFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QImage image;
    MyPNG *myPngImage;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    double scaleFactor = 1;

    QAction *saveAsAct;
    QAction *m_drawCircleAct;
    QAction *m_rgbaFilterAct;
    QAction *m_splitImageAct;
    QAction *m_drawSquareWithDiagonalsAct;
    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
};
#endif // MAINWINDOW_H
