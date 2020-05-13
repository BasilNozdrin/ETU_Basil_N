#include "mypng.h"

MyPNG::MyPNG () :
        fileName(nullptr), bitsInPixel(0), isOpened(false), image(new struct Png) {}

MyPNG::MyPNG (const char *filename)
{
    this->fileName  = nullptr;
    this->isOpened  = true;
    this->image     = new struct Png;
    if (!this->openImage(filename))
    {
        this->isOpened = false;
        delete this->fileName;
        delete this->image;
    }
}

MyPNG::~MyPNG ()
{
    if (!(this->isOpened))
        return;
    int /*x,*/ y;

    /* cleanup heap allocation */
    for (y = 0; y < image->height; y++)
        delete image->row_pointers[y];

    delete image->row_pointers;
    delete this->image;
    delete this->fileName;
}

int MyPNG::openImage (const char *filenameToOpen)
{
    if (isOpened)
        return 1;
    int /*x,*/ y;
    unsigned char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(filenameToOpen, "rb");
    if (!fp) { perror("file could not be opened"); return 1; }

    fread(header, 1, 8, fp);
    if (png_sig_cmp(header, 0, 8))
    { perror("file is not recognized as a PNG"); return 2; }

    image->png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);

    if (!image->png_ptr) { perror("png_create_read_struct failed"); return 3; }

    image->info_ptr = png_create_info_struct(image->png_ptr);
    if (!image->info_ptr) { perror("png_create_info_struct failed"); return 4; }

    if (setjmp(png_jmpbuf(image->png_ptr))) { perror("error during init_io"); return 5; }

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
    if (setjmp(png_jmpbuf(image->png_ptr))) { perror("error during read_image"); return 6; }

    image->row_pointers = new png_bytep[image->height];
    for (y = 0; y < image->height; y++)
        image->row_pointers[y] = new png_byte[png_get_rowbytes(image->png_ptr, image->info_ptr)];

    png_read_image(image->png_ptr, image->row_pointers);

    fclose(fp);

    if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_RGB)
    {
        this->bitsInPixel = 3;
    } else if (png_get_color_type(this->image->png_ptr, this->image->info_ptr) == PNG_COLOR_TYPE_RGBA)
    {
        this->bitsInPixel = 4;
    } else {
        std::cerr << "unsupported file format\n";
        return 7;
    }
    this->isOpened = true;
    this->fileName = new char[strlen(filenameToOpen)+1];
    strcpy(this->fileName, filenameToOpen);

    return 0;
}

int MyPNG::saveImage (const char *filenameToSave) const
{
    if (!isOpened)
        return 1;
//    int x,y;

    /* create file */
    FILE *fp = fopen(filenameToSave, "wb");
    if (!fp) { std::cerr << "file could not be opened"; return 1; }

    /* initialize stuff */
    image->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
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

    png_write_end(image->png_ptr, nullptr);

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
        setBigPixel(x1, y1, lineColor, false, lineThikness, lineColorAlpha);
        setBigPixel(x1, y1, lineColor, true, lineThikness, lineColorAlpha);
        return;
    }
    int centerX = (x2+x1) / 2;
    int centerY = (y2+y1) / 2;
    int radius = abs((x2-x1) / 2);

    // fill circle
    if (isFilled)
        for (int x = 0; x < radius; x++)
        {
            double f_x = sqrt (radius*radius - x*x);
            for (int y = 0; y <= (int)f_x; y++)
            {
                setPixel(centerX+x, centerY+y, mainColor, mainColorAlpha);
                setPixel(centerX+x, centerY-y, mainColor, mainColorAlpha);
                setPixel(centerX-x, centerY+y, mainColor, mainColorAlpha);
                setPixel(centerX-x, centerY-y, mainColor, mainColorAlpha);
            }
        }

    for (int x = 0; x < radius/sqrt(2)+lineThikness; x++)
    {
        double f_x = sqrt (radius*radius - x*x);
        setBigPixel(centerX+x, centerY+(int)f_x, lineColor, true, lineThikness, lineColorAlpha);
        setBigPixel(centerX+x, centerY-(int)f_x, lineColor, true, lineThikness, lineColorAlpha);
        setBigPixel(centerX-x, centerY+(int)f_x, lineColor, true, lineThikness, lineColorAlpha);
        setBigPixel(centerX-x, centerY-(int)f_x, lineColor, true, lineThikness, lineColorAlpha);
    }
    for (int y = 0; y < radius/sqrt(2)+lineThikness; y++)
    {
        double f_y = sqrt (radius*radius - y*y);
        setBigPixel(centerX+(int)f_y, centerY+y, lineColor, false, lineThikness, lineColorAlpha);
        setBigPixel(centerX+(int)f_y, centerY-y, lineColor, false, lineThikness, lineColorAlpha);
        setBigPixel(centerX-(int)f_y, centerY+y, lineColor, false, lineThikness, lineColorAlpha);
        setBigPixel(centerX-(int)f_y, centerY-y, lineColor, false, lineThikness, lineColorAlpha);
    }

}

void MyPNG::rgbaFilter(int chanelToChange, int newValue)
{
    if (!isOpened)
        return;
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
    for (int i = 1; i < n; i++)
        drawLine(0, i*image->height /n, image->width, i*image->height /n, lineColor, thikness, lineColorAlpha);
    for (int j = 1; j < m; j++)
        drawLine(j*image->width /m, 0, j*image->width /m, image->height, lineColor, thikness, lineColorAlpha);
}

void MyPNG::drawSquareWithDiagonals(int x1, int y1,
                                    int sideSize,
                                    int lineThikness,
                                    png_color lineColor, bool isFilled,
                                    int lineColorAlpha,
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

void MyPNG::info() const
{
    std::cout << "Image info:" << std::endl;
    std::cout << "\tSize:                              " << this->image->width << "x" << this->image->height << std::endl;
//    std::cout << "\tColor type:                        " << this->image->color_type << std::endl;
//    std::cout << "\tBit depth:                         " << this->image->bit_depth << std::endl;
//    std::cout << "\tBytes in a row:                    " << this->image->row_pointers << std::endl;
//    std::cout << "\tExpansion of the interlaced image: " << this->image->number_of_passes << std::endl;
}

bool MyPNG::opened() const
{
    return this->isOpened;
}

char *MyPNG::getFileName() const
{
    return this->fileName;
}

bool MyPNG::isOutOfBounds(const int x, const int y) const
{
    if (!isOpened)
        return false;
    if (x < 0 || x >= image->width)
        return true;
    if (y < 0 || y >= image->height)
        return true;
    return false;
}

void MyPNG::setPixel(const int x, const int y, png_color color, int colorAlpha)
{
    if (!isOpened)
        return;

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
        setBigPixel(x1, y1, color, false,thikness, colorAlpha);
        setBigPixel(x1, y1, color, true,thikness, colorAlpha);
        return;
    }
    bool isVertical = abs(y1-y2) > abs(x1-x2);
    if (isVertical)
    { // y = kx+b
        int new_x1, new_x2, new_y1, new_y2;
        if (y1<y2) { new_x1 = x1; new_x2 = x2; new_y1 = y1; new_y2 = y2; }
        else { new_x1 = x2; new_x2 = x1; new_y1 = y2; new_y2 = y1; }
        float k = (float)(new_x2-new_x1) / (float)(new_y2-new_y1);
        for(int y = 0; y <= new_y2-new_y1; y++)
            setBigPixel(new_x1+(int)(k*(float)y), new_y1+y, color, !isVertical, thikness, colorAlpha);
    } else {
        int new_x1, new_x2, new_y1, new_y2;
        if (x1<x2) { new_x1 = x1; new_x2 = x2; new_y1 = y1; new_y2 = y2; }
        else { new_x1 = x2; new_x2 = x1; new_y1 = y2; new_y2 = y1; }
        float k = (float)(new_y2-new_y1) / (float)(new_x2-new_x1);
        for(int x = 0; x <= new_x2-new_x1; x++)
            setBigPixel(new_x1+x, new_y1+int(k*(float)x), color, !isVertical, thikness, colorAlpha);
    }
}
