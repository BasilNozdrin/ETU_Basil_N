#ifndef MYPNG_H
#define MYPNG_H

#include <iostream>

#include <unistd.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
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
                     int thickness,
                     png_color lineColor, bool isFilled,
                     int lineColorAlpha=255,
                     png_color mainColor={255,255,255}, int mainColorAlpha=0);

    void rgbaFilter (int chanelToChange, int newValue);

    void splitImage (int n, int m, // n for Y stripes and m for X stripes
                     int thickness, // or PATH to save parts
                     png_color lineColor, int lineColorAlpha=255);

    void drawSquareWithDiagonals (int leftUpperX, int leftUpperY,
                                  int sideSize, int lineThickness,
                                  png_color lineColor={0,0,0}, int lineColorAlpha=255,
                                  bool isFilled=0,
                                  png_color mainColor={255,255,255}, int mainColorAlpha=0);
    
    void info () const;
    bool opened() const;

protected:
    char *fileName;
    unsigned short int bitsInPixel;
    bool isOpened;
    struct Png *image;

    bool isOutOfBounds (const int x, const int y) const;

    void setPixel (const int x, const int y,
                  png_color color, int colorAlpha=255);

    void setBigPixel (const int x, const int y,
                      png_color color, bool isVertical, int thickness, int colorAlpha=255);

    void drawLine (const int x1, const int y1, const int x2, const int y2,
                   const png_color color, const int thickness, const int colorAlpha=255);
};

#endif // MYPNG_H
