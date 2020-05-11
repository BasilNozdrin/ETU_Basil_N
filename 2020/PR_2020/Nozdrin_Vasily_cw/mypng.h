#ifndef MYPNG_H
#define MYPNG_H

#include <iostream>

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <stdarg.h>
#include <math.h>

#define PNG_DEBUG 3
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
    MyPNG (const char *filenameToOpen);
    MyPNG ();
    ~MyPNG ();

    int openImage (const char *filenameToOpen);
    int saveImage (const char *filenameToSave) const;

    void drawCircle (int leftUpperX, int leftUpperY, // int centerX, centerY
                     int rightBottomX, int rightBottomY, // int radius
                     int thikness,
                     png_color lineColor, bool isFilled=0,
                     int lineColorAlpha=255,
                     png_color mainColor={0,0,0}, int mainColorAlpha=255);

    void rgbaFilter (int chanelToChange, int newValue);

    void splitImage (int n, int m, // n for Y stripes and m for X stripes
                     int thikness, // or PATH to save parts
                     png_color lineColor, int lineColorAlpha=255);

    void drawSquareWithDiagonals (int leftUpperX, int leftUpperY,
                                  int sideSize, int lineThikness,
                                  png_color lineColor, int lineColorAlpha=255,
                                  bool isFilled=0,
                                  png_color mainColor={0,0,0}, int mainColorAlpha=255);

protected:
    bool isOpened;
    struct Png *image;
    unsigned short int bitsInPixel;

    bool isOutOfBounds (const int x, const int y) const;

    void setPixel (const int x, const int y,
                  png_color color, int colorAlpha=255);

    void setBigPixel (const int x, const int y,
                      png_color color, bool isVertical, int thikness, int colorAlpha=255);

    void drawLine (const int x1, const int y1, const int x2, const int y2,
                   const png_color color, const int thikness, const int colorAlpha=255);
};

#endif // MYPNG_H
