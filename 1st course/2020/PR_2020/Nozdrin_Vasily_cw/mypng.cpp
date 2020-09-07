#include "mypng.h"

#define DEBUG 01

MyPNG::MyPNG (const char *filename) :
    isOpened(true), image(new struct Png)
{
    int returnCode = this->openImage(filename);

//    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_GRAY)
//    { this->bitsInPixel = 1; }
//    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_PALETTE)
//    { this->bitsInPixel = 1; }
    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_RGB)
    { this->bitsInPixel = 3; }
    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_RGB_ALPHA)
    { this->bitsInPixel = 4; }
//    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_GRAY_ALPHA)
//    { this->bitsInPixel = 2; }

#if DEBUG
    std::cout << "openImage returned " << returnCode << std::endl;
    std::cout << "Image size is " << this->image->width << "x" << this->image->height << std::endl;
#endif
}

MyPNG::MyPNG () :
    isOpened(false), image(new struct Png) {}

MyPNG::~MyPNG ()
{
#if DEBUG
    std::cout << "MyPNG obj is being deleted" << std::endl;
#endif
    int /*x,*/ y;

    /* cleanup heap allocation */
    for (y = 0; y < image->height; y++)
        delete image->row_pointers[y];

    delete image->row_pointers;

    delete this->image;
}

int MyPNG::openImage (const char *filenameToOpen)
{
    if (isOpened)
        return 1;
    Png *image = this->image;

    int /*x,*/ y;
    unsigned char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(filenameToOpen, "rb");
    if (!fp) { return 1; } // file could not be opened

    fread(header, 1, 8, fp);
    if (png_sig_cmp(header, 0, 8))
    {
        return 2; // file is not recognized as a PNG
    }

    image->png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!image->png_ptr) { return 3; } // png_create_read_struct failed

    image->info_ptr = png_create_info_struct(image->png_ptr);
    if (!image->info_ptr) { return 4; } // png_create_info_struct failed

    if (setjmp(png_jmpbuf(image->png_ptr))) { return 5; } // error during init_io

    png_init_io(image->png_ptr, fp);
    png_set_sig_bytes(image->png_ptr, 8);

    png_read_info(image->png_ptr, image->info_ptr);

    image->width = png_get_image_width(image->png_ptr, image->info_ptr);
    image->height = png_get_image_height(image->png_ptr, image->info_ptr);
    image->color_type = png_get_color_type(image->png_ptr, image->info_ptr);
    image->bit_depth = png_get_bit_depth(image->png_ptr, image->info_ptr);

    image->number_of_passes = png_set_interlace_handling(image->png_ptr);
    png_read_update_info(image->png_ptr, image->info_ptr);

    /* read file */
    if (setjmp(png_jmpbuf(image->png_ptr))) { return 6; } // error during read_image

    image->row_pointers = new png_bytep[image->height];
    for (y = 0; y < image->height; y++)
        image->row_pointers[y] = new png_byte[png_get_rowbytes(image->png_ptr, image->info_ptr)];

    png_read_image(image->png_ptr, image->row_pointers);

    fclose(fp);

    return 0;
}

int MyPNG::saveImage (const char *filenameToSave) const
{
    if (!isOpened)
        return 1;
    Png *image = this->image;
//    int x,y;

    /* create file */
    FILE *fp = fopen(filenameToSave, "wb");
    if (!fp) { return 1; } // file could not be opened

    /* initialize stuff */
    image->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!image->png_ptr) { return 2; } // png_create_write_struct failed

    image->info_ptr = png_create_info_struct(image->png_ptr);
    if (!image->info_ptr) { return 3; }// png_create_info_struct failed

    if (setjmp(png_jmpbuf(image->png_ptr))) { return 4; } // error during init_io

    png_init_io(image->png_ptr, fp);

    /* write header */
    if (setjmp(png_jmpbuf(image->png_ptr))) { return 5; }// error during writing header

    png_set_IHDR(image->png_ptr, image->info_ptr, image->width, image->height,
                 image->bit_depth, image->color_type, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(image->png_ptr, image->info_ptr);

    /* write bytes */
    if (setjmp(png_jmpbuf(image->png_ptr))) { return 6; } // error during writing bytes

    png_write_image(image->png_ptr, image->row_pointers);

    /* end write */
    if (setjmp(png_jmpbuf(image->png_ptr))) { return 7; } // error during end of write

    png_write_end(image->png_ptr, NULL);

    fclose(fp);

    return 0;
}

void MyPNG::drawCircle(int x1, int y1,
                       int x2, int y2,
                       int lineThikness,
                       png_color lineColor, bool isFilled,
                       int lineColorAlpha,
                       png_color mainColor, int mainColorAlpha)
{
    if (!isOpened)
        return;
    if (x1==x2 && y1==y2) {
        setBigPixel(x1, y1, lineColor, 0, lineThikness, lineColorAlpha);
        setBigPixel(x1, y1, lineColor, 1, lineThikness, lineColorAlpha);
        return;
    }
    int centerX = x2-x1;
    int centerY = y2-y1;
    int radius = abs((x2-x1) / 2);

    // fill circle
    if (isFilled)
        for (int x = 0; x < radius; x++)
        {
            float f_x = sqrt (radius*radius - x*x);
            for (int y = 0; y <= f_x; y++)
            {
                setPixel(centerX+x, centerY+y, mainColor, mainColorAlpha);
                setPixel(centerX+x, centerY-y, mainColor, mainColorAlpha);
                setPixel(centerX-x, centerY+y, mainColor, mainColorAlpha);
                setPixel(centerX-x, centerY-y, mainColor, mainColorAlpha);
            }
        }

    for (int x = 0; x < radius/sqrt(2)+lineThikness; x++)
    {
        float f_x = sqrt (radius*radius - x*x);
        setBigPixel(centerX+x, centerY+f_x, lineColor, 1, lineThikness, lineColorAlpha);
        setBigPixel(centerX+x, centerY-f_x, lineColor, 1, lineThikness, lineColorAlpha);
        setBigPixel(centerX-x, centerY+f_x, lineColor, 1, lineThikness, lineColorAlpha);
        setBigPixel(centerX-x, centerY-f_x, lineColor, 1, lineThikness, lineColorAlpha);
    }
    for (int y = 0; y < radius/sqrt(2)+lineThikness; y++)
    {
        float f_y = sqrt (radius*radius - y*y);
        setBigPixel(centerX+f_y, centerY+y, lineColor, 0, lineThikness, lineColorAlpha);
        setBigPixel(centerX+f_y, centerY-y, lineColor, 0, lineThikness, lineColorAlpha);
        setBigPixel(centerX-f_y, centerY+y, lineColor, 0, lineThikness, lineColorAlpha);
        setBigPixel(centerX-f_y, centerY-y, lineColor, 0, lineThikness, lineColorAlpha);
    }

}

void MyPNG::rgbaFilter(int chanelToChange, int newValue)
{
    if (!isOpened)
        return;
    struct Png *image = this->image;
    int x,y;

    chanelToChange %= this->bitsInPixel;

    for (y = 0; y < image->height; y++) {
        png_bytep row = image->row_pointers[y];
        for (x = 0; x < image->width; x++) {
            png_byte *ptr = &(row[x * (this->bitsInPixel)]);
            ptr[chanelToChange] = newValue;
        }
    }
}

void MyPNG::splitImage(int n, int m,
                       int thikness,
                       png_color lineColor, int lineColorAlpha)
{
    if (!isOpened)
        return;
    struct Png *image = this->image;
    for (int i = 1; i < n; i++)
        drawLine(0, i*image->height /n, image->width, i*image->height /n, lineColor, thikness, lineColorAlpha);
    for (int j = 1; j < m; j++)
        drawLine(j*image->width /m, 0, j*image->width /m, image->height, lineColor, thikness, lineColorAlpha);
}

void MyPNG::drawSquareWithDiagonals(int x1, int y1,
                                    int sideSize,
                                    int lineThikness,
                                    png_color lineColor, int lineColorAlpha,
                                    bool isFilled,
                                    png_color mainColor, int mainColorAlpha)
{
    if (!isOpened)
        return;
    // fill square
    if (isFilled)
        for (int x = x1; x < x1+sideSize; x++)
            for (int y = y1; y < y1+sideSize; y++)
                setPixel(x, y, mainColor, mainColorAlpha);

    // draw lines
    drawLine(x1         , y1            , x1+sideSize   , y1            , lineColor, lineThikness, lineColorAlpha);
    drawLine(x1         , y1+sideSize   , x1+sideSize   , y1+sideSize   , lineColor, lineThikness, lineColorAlpha);
    drawLine(x1         , y1            , x1            , y1+sideSize   , lineColor, lineThikness, lineColorAlpha);
    drawLine(x1+sideSize, y1            , x1+sideSize   , y1+sideSize   , lineColor, lineThikness, lineColorAlpha);
    drawLine(x1         , y1            , x1+sideSize   , y1+sideSize   , lineColor, lineThikness, lineColorAlpha);
    drawLine(x1         , y1+sideSize   , x1+sideSize   , y1            , lineColor, lineThikness, lineColorAlpha);
}

bool MyPNG::isOutOfBounds(const int x, const int y) const
{
    if (!isOpened)
        return false;
    struct Png *image = this->image;
    return !(y < image->height) or !(x < image->width);
}

void MyPNG::setPixel(const int x, const int y, png_color color, int colorAlpha)
{
    if (!isOpened)
        return;
    struct Png *image = this->image;

    if (isOutOfBounds(x, y)) { return; }

    int colorp[4] = {color.red, color.green, color.blue, colorAlpha};
    png_byte *ptr = &(image->row_pointers[y][x*(this->bitsInPixel)]);

    for (int i = 0; i < this->bitsInPixel; i++)
        ptr[i] = colorp[i];
}

void MyPNG::setBigPixel(const int x, const int y, png_color color, bool isVertical, int thikness, int colorAlpha)
{
    if (!isOpened)
        return;
    if (thikness == 0) { return; }
    int begin = -(thikness-1)/2;
    int end = (thikness)/2;
    for (int i = begin; i <= end; i++)
    { setPixel(isVertical? x: x+i, isVertical? y+i : y, color, colorAlpha); }
}

void MyPNG::drawLine(const int x1, const int y1, const int x2, const int y2, const png_color color, const int thikness, const int colorAlpha)
{
    if (!isOpened)
        return;
    if (x1==x2 && y1==y2) {
        setBigPixel(x1, y1, color, 0,thikness, colorAlpha);
        setBigPixel(x1, y1, color, 1,thikness, colorAlpha);
        return;
    }
    bool isVertical = abs(y1-y2) > abs(x1-x2);
    if (isVertical)
    { // y = kx+b
        int new_x1, new_x2, new_y1, new_y2;
        if (y1<y2) { new_x1 = x1; new_x2 = x2; new_y1 = y1; new_y2 = y2; }
              else { new_x1 = x2; new_x2 = x1; new_y1 = y2; new_y2 = y1; }
        float k = (new_x2-new_x1) / (new_y2-new_y1);
        for(int y = 0; y <= new_y2-new_y1; y++)
            setBigPixel(new_x1+k*y, new_y1+y, color, !isVertical, thikness, colorAlpha);
    } else {
        int new_x1, new_x2, new_y1, new_y2;
        if (x1<x2) { new_x1 = x1; new_x2 = x2; new_y1 = y1; new_y2 = y2; }
              else { new_x1 = x2; new_x2 = x1; new_y1 = y2; new_y2 = y1; }
        float k = (new_y2-new_y1) / (new_x2-new_x1);
        for(int x = 0; x <= new_x2-new_x1; x++)
            setBigPixel(new_x1+x, new_y1+k*x, color, !isVertical, thikness, colorAlpha);
    }
}
