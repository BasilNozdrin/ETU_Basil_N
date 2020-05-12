#include <iostream>
#include <cstdlib>
#include <cstring>
#include <getopt.h>
#include "mypng.h"

void help();
void errorMessage();

int main(int argc, char *argv[])
{
    auto *image = new MyPNG();
    char *inPath = nullptr;
    auto *outPath = new char[NAME_MAX];
    outPath[0] = '\0';
    bool edit = true;

    if (argc == 1)
    {
        std::cout << "error: no operation specified (use -h for help)" << std::endl;
        delete image;
        delete [] outPath;
        return 0;
    }

    static const std::string    optionString    = "hpcfsqS:D:T:io";
    static const char           *optString      = optionString.c_str();
//#define no_argument            0
//#define required_argument      1
//#define optional_argument      2
    static const struct option longOpts[] =
    {
        //{char *name,    int has_arg,   int *flag, int val; };
        // basic
        {"help",    no_argument,        nullptr,'h' },
        {"info",    no_argument,        nullptr,'p' },
        // functions
        {"circle",  no_argument,        nullptr,'c' },
        {"filter",  no_argument,        nullptr,'f' },
        {"split",   no_argument,        nullptr,'s' },
        {"square",  no_argument,        nullptr,'q' },
        // parameters
        {"single",  required_argument,  nullptr,'S' },
        {"double",  required_argument,  nullptr,'D' },
        {"triple",  required_argument,  nullptr,'T' },
        // input and output
        {"input",   required_argument,  nullptr,'i' },
        {"output",  required_argument,  nullptr,'o' },
        {nullptr,   0,          nullptr, 0  }
    };

    int         option;
    int         longIndex;

    bool        isFilled        =  false;
    png_color   lineColor       = {0,0,0},
                mainColor       = {0,0,0};
    int         lineColorAlpha  =  255,
                mainColorAlpha  =  255,
                x1              =  0,
                y1              =  0,
                x2              =  0,
                y2              =  0,
                lineThickness   =  0,
                chanelToChange  =  0,
                newValue        =  0,
                sideSize        =  0,
                n               =  0,
                m               =  0;
    int         function        =  0;
    // drawCircle                  1
    // rgbaFilter                  2
    // splitImage                  3
    // drawSquareWithDiagonals     4
    // info                        5

//     opterr=0;
    while ((option = getopt_long (argc, argv, optString,
        longOpts, &longIndex)) != -1)
    {
        switch (option)
        {
            case 'c':
            {
            // --circle -D x1 y1 -D x2 y2 -S thickness -T R G B A? -T R G B A?
                function = 1;
                // get first point X
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'D' || (optind + 1 >= argc)
                        || (!std::stoi(optarg) && optarg[0] != '0')
                        || (!std::stoi(argv[optind]) && argv[optind][0] != '0'))
                    {
                        errorMessage();
                        return 0;
                    }
                    x1 = std::stoi(optarg);
                    y1 = std::stoi(argv[optind]);
                }

                // get second point Y
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'D' || (optind + 1 >= argc)
                        || (!std::stoi(optarg) && optarg[0] != '0')
                        || (!std::stoi(argv[optind]) && argv[optind][0] != '0'))
                    {
                        errorMessage();
                        return 0;
                    }
                    x2 = std::stoi(optarg);
                    y2 = std::stoi(argv[optind]);
                }

                // get line thickness
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                    {
                        errorMessage();
                        return 0;
                    }
                    lineThickness = std::stoi(optarg);
                }

                // get lineColor
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'T' || (optind + 1 >= argc)
                        || (!std::stoi(optarg) && optarg[0] != '0')
                        || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
                        || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                    {
                        errorMessage();
                        return 0;
                    }
                    lineColor.red = std::stoi(optarg);
                    lineColor.green = std::stoi(argv[optind]);
                    lineColor.blue = std::stoi(argv[optind + 1]);
                }

                // get lineColorAlpha
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'S'
                        || (!std::stoi(optarg) && optarg[0] != '0'))
                    {
                        lineColorAlpha = 255;
                    } else {
                        lineColorAlpha = std::stoi(optarg) % 256;
                    }
                }

                // get mainColor
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'T' || (optind + 1 >= argc)
                        || (!std::stoi(optarg) && optarg[0] != '0')
                        || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
                        || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                    {
                        isFilled = false;
                    } else {
                        isFilled = true;
                        mainColor.red = std::stoi(optarg);
                        mainColor.green = std::stoi(argv[optind]);
                        mainColor.blue = std::stoi(argv[optind + 1]);
                    }

                }

                // get mainColorAlpha
                {
                    option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                    if (option != 'S'
                        || (!std::stoi(optarg) && optarg[0] != '0'))
                    {
                        mainColorAlpha = 255;
                    } else {
                        mainColorAlpha = std::stoi(optarg) % 256;
                    }
                }
                break;
            }
            case 'f':
            {
                function = 2;
                // --filter -S chanel -T new_value
                // get side size
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                { errorMessage(); return 0; }
                sideSize = std::stoi(optarg);

                // get line thickness
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                { errorMessage(); return 0; }
                lineThickness = std::stoi(optarg);
    // CALL RGBAFilter
                image->rgbaFilter (sideSize, lineThickness);
                // chanel and new_value
                break;
            }
            case 's':
            {
                function = 3;
                // --split -X n m -T thickness -C R G B A?
                // get n and m
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'D' || (optind >= argc)
                    || (!std::stoi(optarg) && optarg[0] != '0')
                    || (!std::stoi(argv[optind]) && argv[optind][0] != '0'))
                { errorMessage(); return 0; }
                n = std::stoi(optarg);
                m = std::stoi(argv[optind]);

                // get line thickness
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                { errorMessage(); return 0; }
                lineThickness = std::stoi(optarg);

                // get lineColor
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'T' || (optind + 2 >= argc)
                    || (!std::stoi(optarg) && optarg[0] != '0')
                    || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
                    || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                { errorMessage(); return 0; }
                lineColor.red = std::stoi(optarg);
                lineColor.green = std::stoi(argv[optind]);
                lineColor.blue = std::stoi(argv[optind + 1]);
                if (std::stoi(argv[optind + 2]) || argv[optind + 2][0] == '0')
                    lineColorAlpha = std::stoi(argv[optind + 2]);


    // CALL SplitImage
                image->splitImage (n, m, lineThickness,
                        lineColor, (lineColorAlpha >= 0)? lineColorAlpha%256: 255);
                break;
            }
            case 'q':
            {
                function = 4;
                // --square -X x1 y1 -S sideSize -T thickness -C R G B A? -C R G B A?
                // get first point X
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'D' || (optind >= argc)
                    || (!std::stoi(optarg) && optarg[0] != '0')
                    || (!std::stoi(argv[optind]) && argv[optind][0] != '0'))
                { errorMessage(); return 0; }
                x1 = std::stoi(optarg);
                y1 = std::stoi(argv[optind]);

                // get side size
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                { errorMessage(); return 0; }
                sideSize = std::stoi(optarg);

                // get line thickness
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0'))
                { errorMessage(); return 0; }
                lineThickness = std::stoi(optarg);

                // get lineColor
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'T' || (optind + 2 >= argc)
                    || (!std::stoi(optarg) && optarg[0] != '0')
                    || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
                    || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                { errorMessage(); return 0; }
                lineColor.red = std::stoi(optarg);
                lineColor.green = std::stoi(argv[optind]);
                lineColor.blue = std::stoi(argv[optind + 1]);
                if (std::stoi(argv[optind + 2]) || argv[optind + 2][0] == '0')
                    lineColorAlpha = std::stoi(argv[optind + 2]);

                // get mainColor
                option = getopt_long(argc, argv, optString, longOpts, &longIndex);
                if (option != 'T' || (optind + 2 >= argc)
                    || (!std::stoi(optarg) && optarg[0] != '0')
                    || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
                    || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0'))
                {
    // CALL DrawSquareWithDiagonals
                    image->drawSquareWithDiagonals (x1, y1, sideSize,
                                       lineThickness, lineColor, false,
                                       (lineColorAlpha >= 0)? lineColorAlpha%256: 255);
                } else {
                    mainColor.red = std::stoi(optarg);
                    mainColor.green = std::stoi(argv[optind]);
                    mainColor.blue = std::stoi(argv[optind + 1]);
                    if (std::stoi(argv[optind + 2]) || argv[optind + 2][0] == '0')
                        mainColorAlpha = std::stoi(argv[optind + 2]);
    // CALL DrawSquareWithDiagonals
                    image->drawSquareWithDiagonals (x1, y1, sideSize,
                                       lineThickness, lineColor, true,
                                       (lineColorAlpha >= 0)? lineColorAlpha%256: 255,
                                       mainColor, (mainColorAlpha >= 0)? mainColorAlpha%256: 255);
                }
                break;
            }

            case 'i':
            {
                if (optarg)
                {
                    inPath = new char[strlen(optarg) + 1];
                    strcpy(inPath, optarg);
                } else { errorMessage(); return 0; }
                break;
            }
            case 'o':
            {
                edit = false;
                strcpy(outPath, optarg);
                break;
            }
            case 'p':
            {
                function = 5;
                break;
            }
            case 'h':
            case '?':
            default:
                help();
                return 0;
        }
    }

    argc -= optind;
    argv += optind;

//    std::cout << "argc = " << argc << std::endl << argv[argc-1] << std::endl;

    // open file
    if (inPath)
    {
        if (image->openImage(inPath))
        { return 0; }
    } else {
        if (strstr(argv[argc-1], ".png"))
        {
            if (image->openImage(argv[argc-1]))
                return 0;
        } else {
            errorMessage();
        }
    }

    // process file
    switch (function)
    {
        case 1:
        {
            image->drawCircle(x1, y1, x2, y2,
                    lineThickness, lineColor, isFilled,
                    lineColorAlpha, mainColor, mainColorAlpha);
            break;
        }
        case 2:
        {
            image->rgbaFilter(chanelToChange, newValue);
            break;
        }
        case 3:
        {
            image->splitImage(n, n, lineThickness, lineColor, lineColorAlpha);
            break;
        }
        case 4:
        {
            image->drawSquareWithDiagonals(x1, y1, sideSize,
                              lineThickness, lineColor, isFilled,
                              lineColorAlpha, mainColor, mainColorAlpha);
            break;
        }
        case 5:
        {
            image->info();
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }

    if (edit)
        strcpy(outPath, image->getFileName());

    image->saveImage(outPath);

    delete image;
    delete inPath;
    delete [] outPath;
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

    std::cout << "\tWARNING\n"
                 "\t\tAlways set alpha chanel. RGB images will ignore alpha value\n";

    std::cout << "\tOPERATIONS" << std::endl;
    std::cout << "\t\t-h, --help -?\n"
                 "\t\t\tDisplay the general syntax." << std::endl;
    std::cout << "\t\t-p, --info\n"
                 "\t\t\tDisplay picture information." << std::endl;
    std::cout << "\t\t-c --circle\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-D [coords1] -D [coords2] -S [lineThickness] -T [lineColor] -S [alpha] -T [fillColor] -S [alpha]\n";
    std::cout << "\t\t-f --filter\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-S [chanelToChange] -S [valueToSet]\n";
    std::cout << "\t\t-s --split\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-D [coords1] -S [n] -S [m] -T [lineColor] -T [fillColor]\n";
    std::cout << "\t\t-q --square\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-D [coords1] -S [sideSize] -S [lineThickness] -T [lineColor] -T [fillColor]\n";

    std::cout << "\tOPTIONS" << std::endl;
    std::cout << "\t\t-i, --thickness\n"
                 "\t\t\tan integer that corresponds with line thickness" << std::endl;
    std::cout << "\t\t-o, --size\n"
                 "\t\t\tan integer that corresponds with square size" << std::endl;

    std::cout << "\t\t-S, --single\n"
                 "\t\t\tone integer value" << std::endl;
    std::cout << "\t\t-D, --double\n"
                 "\t\t\tpair of integers as coordinates a point" << std::endl;
    std::cout << "\t\t-T, --triple\n"
                 "\t\t\tthree or four integers for RGB or RGBA color" << std::endl;
}

void errorMessage()
{
    std::cout << "Error: wrong usage" << std::endl <<
              "use './Nozdrin_Vasily_cw {-h --help}' "
              "with an operation for available options" << std::endl;
}
