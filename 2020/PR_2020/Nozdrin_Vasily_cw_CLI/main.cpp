#include <iostream>
#include <unistd.h>
#include <cstdlib>

// #include <getopt.h>
// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>
// #include <locale.h>

#include "mypng.h"



int main(int argc, char *argv[])
{
    MyPNG image;

    if (argc >= 2)
    {
        if(strstr(argv[argc-1], ".png"))
        {
            if(read_png_file(argv[argc-1], &image)) return 0;
            flag_in = 0;
        } else {
            create_new_image(1920, 1080);
            read_png_file("out.png", &image);
            process_file(&image);
        }
    } else {
        printf("This program does nothing! Please, check this manual.\n");
        printHelp();
        return 0;
    }

    /* Наличие справки, которая распечатывается при вызове утилиты без аргументов или стандартными ключами (-h, –help)
     * По-умолчанию последним аргументов утилите должно передаваться имя bmp файла, в который и будут записаны изменения,
     * однако это можно переопределить соответствующими ключами, как и имя выходного файла.
     * 
     * Утилита должна иметь функцию печати подробной информации о bmp-файле
     * В случае, если программой будут поддерживаться не все версии bmp-файлов, программа должна выводить об этом внятное сообщение, а не крашиться.
     * Для каждого инструмента должен быть соответствующий ключ и ключи для его конфигурирования. Например, рисование прямоугольника может выглядеть как-то так:
     * ice-jack@ice-pc ~> mypaint --rectangle --start 0 0 --end 100 50 --color red picture.bmp
     */
    static const char *optString = "hcfsq";


// #define no_argument            0
// #define required_argument      1
// #define optional_argument      2
    static const struct option longOpts[] =
            {
                    //{char *name,    int has_arg,   int *flag, int val; };
                    {"help",        no_argument,        NULL, 'h' },
                    {"circle",      no_argument,        NULL, 'c' },
                    {"filter",      no_argument,        NULL, 'f' },
                    {"split",       no_argument,        NULL, 's' },
                    {"square",      no_argument,        NULL, 'q' },

                    {"start",       required_argument,  NULL, 'S' },
                    {"end",         required_argument,  NULL, 'E' },

                    {"color",       required_argument,  NULL, 'C' },
                    {"fillColor",   required_argument,  NULL, 'F' },

                    {"input",       required_argument,  NULL, 'i' },
                    {NULL,          0,                  NULL,  0  }
            };

    int option = 0, longIndex = 0;
    
    union rgba rgba1, rgba2;
    
    char *in = NULL, *out = NULL;
    
    struct g_args global_args;
    
    global_args.width = 0;
    global_args.figure = "\0";
    global_args.input = "\0";
    global_args.output = "\0";
    global_args.rad = 0;
    global_args.rgba1.ptr[0] = 0;
    global_args.rgba1.ptr[1] = 0;
    global_args.rgba1.ptr[2] = 0;
    global_args.rgba1.ptr[3] = 0;
    global_args.rgba2.ptr[0] = 0;
    global_args.rgba2.ptr[1] = 0;
    global_args.rgba2.ptr[2] = 0;
    global_args.rgba2.ptr[3] = 0;
    global_args.x1 = 0;
    global_args.x2 = 0;
    global_args.y1 = 0;
    global_args.y2 = 0;
    global_args.mode = 0;
    
//     opterr=0;
    while ((option = getopt_long (argc, argv, optString,
        longOpts, &longIndex)) != -1)
    {
        switch (option)
        {
            case 'w':
                global_args.width = CharToInt(optarg);
                printf("width %d\n", global_args.width);
                break;
            case 'i':
                global_args.input = optarg;
                printf("input file readed %s\n", global_args.input);
                break;
            case 'o':
                global_args.output = optarg;
                printf("output file readed %s\n", global_args.output);
                break;
            case 's':
                global_args.x1 = CharToInt(strtok(optarg, "xX \0\n"));
                global_args.y1 = CharToInt(strtok(NULL, "xX \0\n"));
                printf("x1 = %d y1 = %d\n", global_args.x1, global_args.y1);
                break;
            case 'e':
                global_args.x2 = CharToInt(strtok(optarg, "xX \0\n"));
                global_args.y2 = CharToInt(strtok(NULL, "xX \0\n"));
                printf("x2 = %d y2 = %d\n", global_args.x2, global_args.y2);
                break;
            case 'r':
                global_args.rad = CharToInt(optarg);
                printf("radius %d\n", global_args.rad);
                break;
            case 'f':
                global_args.figure = optarg;
                printf("figure %s selected\n", global_args.figure);
                break;
            case 'b':
                global_args.rgba1.ptr[0] = CharToInt(strtok(optarg, "xX \0\n"));
                global_args.rgba1.ptr[1] = CharToInt(strtok(NULL, "xX \0\n"));
                global_args.rgba1.ptr[2] = CharToInt(strtok(NULL, "xX \0\n"));
                global_args.rgba1.ptr[3] = CharToInt(strtok(NULL, "xX \0\n"));
                printf("brush color %d %d %d %d\n", global_args.rgba1.ptr[0], global_args.rgba1.ptr[1],
                        global_args.rgba1.ptr[2], global_args.rgba1.ptr[3]);
                break;
            case 'c':
                global_args.rgba2.ptr[0] = CharToInt(strtok(optarg, "xX \0\n"));
                global_args.rgba2.ptr[1] = CharToInt(strtok(NULL, "xX \0\n"));
                global_args.rgba2.ptr[2] = CharToInt(strtok(NULL, "xX \0\n"));
                global_args.rgba2.ptr[3] = CharToInt(strtok(NULL, "xX \0\n"));
                printf("fill color %d %d %d %d\n", global_args.rgba2.ptr[0], global_args.rgba2.ptr[1],
                        global_args.rgba2.ptr[2], global_args.rgba2.ptr[3]);
                break;
            default:
                printf("use './Nozdrin_Vasily_cw {-h --help}' with an operation for available options\n");
                break;
        }
    }
    
    int x1 = global_args.x1, x2 = global_args.x2, y1 = global_args.y1, y2 = global_args.y2, width = global_args.width, rad = global_args.rad;
    
    rgba1 = global_args.rgba1;
    
    rgba2 = global_args.rgba2;
    
    if ((x1 > x2 || y1 > y2) && !rad) {
        printf("Ошибка! Введены неверные координаты! Координаты начала обработки "
               "должны быть меньше координат конца обработки!\n");
        return 0;
    }
    
    if (argc == 1) help();
    
    struct Png image;
    
    read_png_file(global_args.input, &image);
    
    if (png_get_color_type(image.png_ptr, image.info_ptr) != PNG_COLOR_TYPE_RGBA)
    {
        printf("Ошибка! Данная программа работает только с файлами PNG типа RGBA!\n");
        exit(0);
    }
    
    if (!strcmp(global_args.figure, (const char *) &"reflecth"))
    {
        reflect(&image, x1, y1, x2, y2, 0);
    } else if (!strcmp(global_args.figure, (const char *) &"reflectv"))
    {
        reflect(&image, x1, y1, x2, y2, 1);
    } else if (!strcmp(global_args.figure, (const char *) &"rect"))
    {
        rect(&image, x1, y1, x2, y2, width, &rgba1);
    } else if (!strcmp(global_args.figure, (const char *) &"frect"))
    {
        frect(&image, x1, y1, x2, y2, width, &rgba1, &rgba2);
    } else if (!strcmp(global_args.figure, (const char *) &"pentagram"))
    {
        if (rad == 0 && x2 != 0 && y2 != 0)
        {
            rad = (x2 - x1) / 2;
        } else makesquare(&x1, &x2, &y1, &y2);
        pentagram(&image, rad, x1, y1, width, &rgba1, &rgba2);
    } else if (!strcmp(global_args.figure, (const char *) &"hex"))
    {
        if (rad != 0 && x2 == 0 && y2 == 0)
        {
            x2 = x1 + rad;
            y2 = y1 + rad;
            x1 = x1 - rad;
            y1 = y1 - rad;
        } else makesquare(&x1, &x2, &y1, &y2);
        hex(&image, x1, y1, x2, y2, width, &rgba1);
    } else if (!strcmp(global_args.figure, (const char *) &"fhex"))
    {
        if (rad != 0 && x2 == 0 && y2 == 0)
        {
            x2 = x1 + rad;
            y2 = y1 + rad;
            x1 = x1 - rad;
            y1 = y1 - rad;
        } else makesquare(&x1, &x2, &y1, &y2);
        fhex(&image, x1, y1, x2, y2, width, &rgba1, &rgba2);
    } else {
        pinfo(&image);
    }
    
    write_png_file(global_args.output, &image);
    
    return 0; 
    
    
    std::string outPath1 = "./WorkExamples/out1.png";
    std::string outPath2 = "./WorkExamples/out2.png";

    MyPNG *img2 = new MyPNG(inPath2.c_str());
    if (!img2) { std::cerr << "fileOpen error" <<std::endl; return 1; }

    img2->drawCircle(10, 10, 200, 200, 5, {0,0,0}, 1, 255, {255,0,0}, 255);
    img2->rgbaFilter(2, 255);
    img2->splitImage(3, 4, 3, {150,0,0});
    
    std::cout << "saveImage returned " << img2->saveImage(outPath2.c_str()) << std::endl;

    delete img2;

    return 0;
}

void help(){
    printf("usage: ./Nozdrin_Vasily_cw \n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("1) -l -s <x1> <y1> -e <x2> <y2> -c <R> <G> <B> <A_C> -w <val> - DRAW A LINE\n");
    printf("    --line --start <x1> <y1> --end <x2> <y2> --colour <R> <G> <B> <A_C> --width <val>\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("2) -t -x <x1> <y1> -y <x2> <y2> -z <x3> <y3> -c <R> <G> <B> <A_C> -w <val> -c <R> <G> <B> <A_C> - DRAW A TRIANGLE\n");
    printf("    --triangle -x <x1> <y1> -y <x2> <y2> -z <x3> <y3> --colour <R> <G> <B> <A_C> --width <val> --colour <R> <G> <B> <A_C>\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("3) -r -c <R> <G> <B> <A_C> -c <R> <G> <B> <A_C> - FIND THE BIGGEST REG OF GIVEN COLOUR AND REPAINT IT\n");
    printf("    --regtangle --colour <R> <G> <B> <A_C> --colour <R> <G> <B> <A_C>\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("4) -i <input_file_name> -a <width> <height> - MAKE A COLLAGE OF A GIVEN PICTURE\n");
    printf("    --input <input_file_name> --application <width> <height>\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("--You can also specify INPUT_FILE and OUTPUT_FILE: -i (--input) <input_file_name> -o (--output) <output_file_name>\n");
    printf("(By default, the file name is specified as the last argument)\n");
    printf("--For collage it is necessary to specify input file\n");
    printf("-h (--help) -? - help\n");
    printf("-d (--data) - SHOW PICTURE INFO\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
}