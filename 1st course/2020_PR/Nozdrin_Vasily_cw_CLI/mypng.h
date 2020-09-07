#ifndef MYPNG_H
#define MYPNG_H

#include <iostream>

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cerrno>

#include <png.h>

struct Png
{
    int width, height;
    png_byte color_type;
    png_byte bit_depth;

    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep *row_pointers;
};


class MyPNG
{
public:
    MyPNG ();
    explicit MyPNG (const char *filenameToOpen);
    ~MyPNG ();

    int openImage (const char *filenameToOpen);
    int saveImage (const char *filenameToSave) const;

    void drawCircle (int x1, int y1,
                     int x2, int y2,
                     int thickness,
                     png_color lineColor, bool isFilled,
                     int lineColorAlpha=255,
                     png_color mainColor={255,255,255}, int mainColorAlpha=0);

    void rgbaFilter (int chanelToChange, int newValue);

    void splitImage (int n, int m, // n for Y stripes and m for X stripes
                     int thickness, // or PATH to save parts
                     png_color lineColor, int lineColorAlpha=255);

    void drawSquareWithDiagonals (int x1, int x2,
                                  int sideSize, int lineThickness,
                                  png_color lineColor={0,0,0}, bool isFilled=false,
                                  int lineColorAlpha=255,
                                  png_color mainColor={255,255,255}, int mainColorAlpha=0);

    void compress();

    void info () const;
    bool opened() const;
    char *getFileName() const;

protected:
    char *fileName;
    unsigned short int bitsInPixel{};
    bool isOpened;
    struct Png *image;

    bool isOutOfBounds (int x, int y) const;

    void setPixel (int x, int y,
                  png_color color, int colorAlpha=255);

    png_color getPixel(int, int);
    png_byte getAlpha (int x, int y);

    void setBigPixel (int x, int y,
                      png_color color, bool isVertical, int thickness, int colorAlpha=255);

    void drawLine (int x1, int y1, int x2, int y2,
                   png_color color, int thickness, int colorAlpha=255);
};

#endif // MYPNG_H
