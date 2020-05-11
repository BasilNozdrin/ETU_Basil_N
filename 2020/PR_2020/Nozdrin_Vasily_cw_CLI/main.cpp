#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>

#include <getopt.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <locale.h>

#include "mypng.h"

void help();
void errorMsg()
{
    std::cout << "Error: wrong usage" << std::endl <<
              "use './Nozdrin_Vasily_cw {-h --help}' "
              "with an operation for available options" << std::endl;
}

int main(int argc, char *argv[])
{
    MyPNG *image = new MyPNG();
/*
    if (argc >= 2)
    {
        if(strstr(argv[argc-1], ".png"))
        {
            if (image->openImage(argv[argc-1])) return 0;
        }
    } else {
        std::cout << "error: no operation specified (use -h for help)" << std::endl;
//        help();
        return 0;
    }

    /* Наличие справки, которая распечатывается при вызове утилиты без аргументов или стандартными ключами (-h, –help)
     * По-умолчанию последним аргументов утилите должно передаваться имя bmp файла, в который и будут записаны изменения,
     * однако это можно переопределить соответствующими ключами, как и имя выходного файла.
     * 
     * Утилита должна иметь функцию печати подробной информации о bmp-файле
     * В случае, если программой будут поддерживаться не все версии bmp-файлов, программа должна выводить об этом внятное сообщение, а не крашиться.
     * Для каждого инструмента должен быть соответствующий ключ и ключи для его конфигурирования. Например, рисование прямоугольника может выглядеть как-то так:
     * ice-jack@ice-pc ~> ./Nozdrin_Vasily_cw --rectangle --start 0 0 --end 100 50 --color red picture.bmp
     *//*
    static const std::string    optionString    = "hicfsqC:T:X:Y:io";
    static const char           *optString      = optionString.c_str();
//#define no_argument            0
//#define required_argument      1
//#define optional_argument      2
    static const struct option longOpts[] =
    {
        //{char *name,    int has_arg,   int *flag, int val; };
        // basic
        {"help",        no_argument,        NULL,   'h' },
        {"info",        no_argument,        NULL,   'i' },
        // functions
        {"circle",      no_argument,        NULL,   'c' },
        {"filter",      no_argument,        NULL,   'f' },
        {"split",       no_argument,        NULL,   's' },
        {"square",      no_argument,        NULL,   'q' },
        // parameters
        {"color",       required_argument,  NULL,   'C' },
        {"thickness",   required_argument,  NULL,   'T' },
        {"start",       required_argument,  NULL,   'X' },
        {"end",         required_argument,  NULL,   'Y' },
        {"size",        required_argument,  NULL,   'S' },

        {"input",       required_argument,  NULL, 'i'},
        {"output",      required_argument,  NULL, 'o'},
        {NULL,          0,                  NULL,  0  }
    };

    int         option;
    int         longIndex;

    png_color   lineColor       = {0,0,0};
    int         lineColorAlpha  = -1;
    png_color   mainColor       = {0,0,0};
    int         mainColorAlpha  = -1;
    int         x1              = 0,
                y1              = 0;
    int         x2              = 0,
                y2              = 0;
    int         lineThickness   = 0;
    int         sideSize        = 0;
    int         chanelToChange  = 0;
    int         newValue        = 0;

//     opterr=0;
    while ((option = getopt_long (argc, argv, optString,
        longOpts, &longIndex)) != -1)
    {
        switch (option)
        {
            case 'i':
            {
                image->info();
                break;
            }
            case 'c':
            {
            // --circle -X x1 y1 -Y x2 y2 -T thickness -C R G B A? -C R G B A?
                // get first point X
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'X' || (optind >= argc)
                || (!atoi(optarg) && optarg[0] != '0')
                || (!atoi(argv[optind]) && argv[optind][0] != '0'))
                { errorMsg(); return 0; }
                x1 = atoi(optarg);
                y1 = atoi(argv[optind]);

                // get second point Y
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'Y' || (optind >= argc)
                || (!atoi(optarg) && optarg[0] != '0')
                || (!atoi(argv[optind]) && argv[optind][0] != '0'))
                { errorMsg(); return 0; }
                x2 = atoi(optarg);
                y2 = atoi(argv[optind]);

                // get line thickness
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'T' || (!atoi(optarg) && optarg[0] != '0'))
                { errorMsg(); return 0; }
                lineThickness = atoi(optarg);

                // get lineColor
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'C' || (optind + 2 >= argc)
                || (!atoi(optarg) && optarg[0] != '0')
                || (!atoi(argv[optind]) && argv[optind][0] != '0')
                || (!atoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                { errorMsg(); return 0; }
                lineColor.red = atoi(optarg);
                lineColor.green = atoi(argv[optind]);
                lineColor.blue = atoi(argv[optind + 1]);
                if (atoi(argv[optind + 2]) || argv[optind + 2][0] == '0')
                    lineColorAlpha = atoi(argv[optind + 2]);

                // get mainColor
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'C' || (optind + 2 >= argc)
                    || (!atoi(optarg) && optarg[0] != '0')
                    || (!atoi(argv[optind]) && argv[optind][0] != '0')
                    || (!atoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                {
        // CALL DrawCircle
                    image->drawCircle (x1, y1, x2, y2,
                            lineThickness, lineColor, false,
                           (lineColorAlpha >= 0)? lineColorAlpha%256: 255);
                } else {
                    mainColor.red = atoi(optarg);
                    mainColor.green = atoi(argv[optind]);
                    mainColor.blue = atoi(argv[optind + 1]);
                    if (atoi(argv[optind + 2]) || argv[optind + 2][0] == '0')
                        mainColorAlpha = atoi(argv[optind + 2]);
        // CALL DrawCircle
                    image->drawCircle (x1, y1, x2, y2,
                           lineThickness, lineColor, true,
                           (lineColorAlpha >= 0)? lineColorAlpha%256: 255,
                           mainColor, (mainColorAlpha >= 0)? mainColorAlpha%256: 255);
                    std::cout << "here\n";
                }
                break;
            }
            case 'o':
                break;

            case 'h':
            case '?':
            default:
                help();
                break;
        }
    }
*/
//    std::string outPath = "./WorkExamples/out2.png";
//    image->saveImage(outPath.c_str());
//    return 0;

    std::string inPath = "./WorkExamples/in2.png";
    std::string outPath = "./WorkExamples/out2.png";
    MyPNG *img = new MyPNG(inPath.c_str());
    if (!img) { std::cerr << "fileOpen error" <<std::endl; return 1; }
    img->drawCircle(10, 10, 100, 100, 3, {200,50,50}, 1, 255, {0,0,0}, 0);
    img->saveImage(outPath.c_str());
    delete img;
    return 0;
}

void help(){
    std::cout << "\tNAME\n"
                 "\t\tNozdrin_Vasily_cw -- png editor\n";

    std::cout << "\tSYNOPSIS\n"
                 "\t\t./Nozdrin_Vasily_cw <operation> [options] [targets]\n";

    std::cout << "\tDESCRIPTION\n"
                 "\t\tThis program is PNG editor that supports "
                 "only RGB and RGBA images\n";

    std::cout << "\tOPERATIONS" << std::endl;
    std::cout << "\t\t-h, --help -?\n"
                 "\t\t\tDisplay the general syntax." << std::endl;
    std::cout << "\t\t-i, --info\n"
                 "\t\t\tDisplay picture information." << std::endl;
    std::cout << "\t\t-c --circle\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-X [coords1] -Y [coords2] -T [value] -C [lineColor] -C [fillColor]\n";

    std::cout << "\tOPTIONS" << std::endl;
    std::cout << "\t\t-C, --color\n"
                 "\t\t\t 3 or 4 integers for RGB or RGBA" << std::endl;
    std::cout << "\t\t-X, --start\n"
                 "\t\t\tpair of integers as coordinates of first point" << std::endl;
    std::cout << "\t\t-Y, --end\n"
                 "\t\t\tpair of integers as coordinates of second point" << std::endl;
    std::cout << "\t\t-T, --thickness\n"
                 "\t\t\tan integer that corresponds with line thickness" << std::endl;
    std::cout << "\t\t-S, --size\n"
                 "\t\t\tan integer that corresponds with square size" << std::endl;

/*
    std::cout << "1) -l -s <x1> <y1> -e <x2> <y2> -c <R> <G> <B> <A_C> -w <val> - DRAW A LINE" << std::endl;

    printf("    --line --start <x1> <y1> --end <x2> <y2> --colour <R> <G> <B> <A_C> --width <val>\n");
    printf("3) -r -c <R> <G> <B> <A_C> -c <R> <G> <B> <A_C> - FIND THE BIGGEST REG OF GIVEN COLOUR AND REPAINT IT\n");
    printf("    --regtangle --colour <R> <G> <B> <A_C> --colour <R> <G> <B> <A_C>\n");
    printf("4) -i <input_file_name> -a <width> <height> - MAKE A COLLAGE OF A GIVEN PICTURE\n");
    printf("    --input <input_file_name> --application <width> <height>\n");
    printf("--You can also specify INPUT_FILE and OUTPUT_FILE: -i (--input) <input_file_name> -o (--output) <output_file_name>\n");
    printf("(By default, the file name is specified as the last argument)\n");
    printf("--For collage it is necessary to specify input file\n");
    */
}