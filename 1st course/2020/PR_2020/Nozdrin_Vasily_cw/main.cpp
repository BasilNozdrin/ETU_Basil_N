#include "mainwindow.h"
#include "mypng.h"

#include <iostream>
#include <QApplication>
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    MainWindow  window;
    window.show();

    return app.exec();

    std::string inPath1 = "./WorkExamples/in1.png";
    std::string inPath2 = "./WorkExamples/in2.png";
    std::string outPath1 = "./WorkExamples/out1.png";
    std::string outPath2 = "./WorkExamples/out2.png";

    MyPNG *img1 = new MyPNG(inPath1.c_str());
    if (!img1) { std::cerr << "fileOpen error" <<std::endl; return 1; }

    MyPNG *img2 = new MyPNG(inPath2.c_str());
    if (!img2) { std::cerr << "fileOpen error" <<std::endl; return 1; }

//    img1->drawSquareWithDiagonals(50,50,128,5,{255,0,0},255,1,{0,128,128});
    img1->drawCircle(10, 10, 200, 200, 5, {0,0,0}, 1, 255, {255,0,0}, 255); //50, 50, 100, 100, 5, {255,0,0}, 1, 255,{0,128,128}, 255);
    std::cout << "saveImage returned " << img1->saveImage(outPath1.c_str()) << std::endl;

    img2->rgbaFilter(2, 255);
    img2->splitImage(3, 4, 3, {150,0,0});
    std::cout << "saveImage returned " << img2->saveImage(outPath2.c_str()) << std::endl;

    delete img1;
    delete img2;

    return 0;
}
