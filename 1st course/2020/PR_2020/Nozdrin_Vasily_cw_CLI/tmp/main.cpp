#include <iostream>
#include <cstdlib>
#include <cstring>
#include <getopt.h>
#include "pngedit.h"

void help();
void errorMessage(const char* errStr = nullptr);

int get_one_value(int argc, char **argv, const char* optString, const struct option longOpts[], int &longIndex, int &value)
{
    int option = getopt_long(argc, argv, optString, longOpts, &longIndex);
    if (option != 'S' || (!std::stoi(optarg) && optarg[0] != '0')) {
        return 1;
    }
    value = std::stoi(optarg);
    return 0;
}
int get_two_values(int argc, char **argv, const char* optString, const struct option longOpts[], int &longIndex, int &value1, int &value2)
{
    int option = getopt_long(argc, argv, optString, longOpts, &longIndex);
    if (option != 'D' || (optind >= argc)
        || (!std::stoi(optarg) && optarg[0] != '0')
        || (!std::stoi(argv[optind]) && argv[optind][0] != '0')) {
        return 1;
    }
    value1 = std::stoi(optarg);
    value2 = std::stoi(argv[optind]);
    return 0;
}
int get_color(int argc, char **argv, const char* optString, const struct option longOpts[], int &longIndex, png_color &color)
{
    int option = getopt_long(argc, argv, optString, longOpts, &longIndex);
    if (option != 'T' || (optind + 1 >= argc)
    || (!std::stoi(optarg) && optarg[0] != '0')
    || (!std::stoi(argv[optind]) && argv[optind][0] != '0')
    || (!std::stoi(argv[optind + 1]) && argv[optind + 1][0] != '0')) {
        return 1;
    }
    color.red = std::stoi(optarg) % 256;
    color.green = std::stoi(argv[optind]) % 256;
    color.blue = std::stoi(argv[optind + 1]) % 256;
    return 0;
}

int main(int argc, char *argv[])
{
    auto *image = new PNGEdit();
    char *inPath = nullptr;
    auto *outPath = new char[NAME_MAX];
    outPath[0] = '\0';
    bool edit = true;

    if (argc == 1) {
        std::cout << "error: no operation specified (use -h for help)" << std::endl;
        delete image;
        delete [] outPath;
        return 0;
    }

    static const std::string    optionString    = "?hpcfsqS:D:T:i:o:";
    static const char           *optString      = optionString.c_str();

    static const struct option longOpts[] = {
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

    while ((option = getopt_long (argc, argv, optString, longOpts, &longIndex)) != -1) {
        switch (option) {
            case 'c': {
                if (!function) function = 1;
                else break;
                if (get_two_values(argc, argv, optString, longOpts, longIndex, x1, y1)) {
                    errorMessage();
                    return 0;
                }
                if (get_two_values(argc, argv, optString, longOpts, longIndex, x2, y2)) {
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, lineThickness)) {
                    errorMessage();
                    return 0;
                }
                if (get_color(argc, argv, optString, longOpts, longIndex, lineColor)){
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, lineColorAlpha)) {
                    errorMessage();
                    return 0;
                }
                lineColorAlpha %= 256;
                isFilled = (get_color(argc, argv, optString, longOpts, longIndex, mainColor) == 0);
                get_one_value(argc, argv, optString, longOpts, longIndex, mainColorAlpha);
                mainColorAlpha %= 256;
                break;
            }
            case 'f': {
                if (!function) function = 2;
                else break;
                if (get_two_values(argc, argv, optString, longOpts, longIndex, chanelToChange, newValue)) {
                    errorMessage();
                    return 0;
                }
                break;
            }
            case 's': {
                if (!function) function = 3;
                else break;
                if (get_two_values(argc, argv, optString, longOpts, longIndex, n, m)) {
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, lineThickness)) {
                    errorMessage();
                    return 0;
                }
                if (get_color(argc, argv, optString, longOpts, longIndex, lineColor)){
                    errorMessage();
                    return 0;
                }
                get_one_value(argc, argv, optString, longOpts, longIndex, lineColorAlpha);
                lineColorAlpha %= 256;
                break;
            }
            case 'q': {
                if (!function) function = 4;
                else break;
                if (get_two_values(argc, argv, optString, longOpts, longIndex, x1, y1)) {
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, sideSize)) {
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, lineThickness)) {
                    errorMessage();
                    return 0;
                }
                if (get_color(argc, argv, optString, longOpts, longIndex, lineColor)){
                    errorMessage();
                    return 0;
                }
                if (get_one_value(argc, argv, optString, longOpts, longIndex, lineColorAlpha)) {
                    errorMessage();
                    return 0;
                }
                lineColorAlpha %= 256;
                isFilled = (get_color(argc, argv, optString, longOpts, longIndex, mainColor) == 0);
                get_one_value(argc, argv, optString, longOpts, longIndex, mainColorAlpha);
                mainColorAlpha %= 256;
                if (get_one_value(argc, argv, optString, longOpts, longIndex, mainColorAlpha)) {
                    errorMessage();
                    return 0;
                }
                mainColorAlpha %= 256;
                break;
            }
            case 'i': {
                if (optarg) {
                    inPath = new char[strlen(optarg) + 1];
                    strcpy(inPath, optarg);
                } else {
                    errorMessage();
                    return 0;
                }
                break;
            }
            case 'o': {
                edit = false;
                strcpy(outPath, optarg);
                break;
            }
            case 'p': {
                if (!function) function = 5;
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
    // open file
    if (inPath) {
        if (image->openImage(inPath)) {
            errorMessage("Wrong filename or program could not open this file");
            return 0;
        }
    } else {
        if (strstr(argv[argc-1], ".png")) {
            if (image->openImage(argv[argc-1])) {
                errorMessage("Wrong filename or program could not open this file");
                return 0;
            }
        } else {
            errorMessage("Wrong filename");
            return 0;
        }
    }

    switch (function) {
        case 1: {
            if (abs(x1-x2) != abs(y1-y2)) {
                errorMessage("Wrong input. You're trying to draw an ellipse, but this program can only draw circles");
                break;
            }
            image->drawCircle(x1, y1, x2, y2,
                    lineThickness, lineColor, isFilled,
                    lineColorAlpha, mainColor, mainColorAlpha);
            break;
        }
        case 2: {
            image->rgbaFilter(chanelToChange, newValue);
            break;
        }
        case 3: {
            image->splitImage(n, m, lineThickness, lineColor, lineColorAlpha);
            break;
        }
        case 4: {
            image->drawSquareWithDiagonals(x1, y1, sideSize,
                              lineThickness, lineColor, isFilled,
                              lineColorAlpha, mainColor, mainColorAlpha);
            break;
        }
        case 5: {
            image->info();
            break;
        }
        default: {
            errorMessage("No operation selected");
            return 0;
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

void help()
{
    std::cout << "\tNAME\n"
                 "\t\tNozdrin_Vasily_cw -- png editor\n";

    std::cout << "\tSYNOPSIS\n"
                 "\t\t./Nozdrin_Vasily_cw <operation> [options] [targets]\n";

    std::cout << "\tDESCRIPTION\n"
                 "\t\tThis program is PNGEdit editor that supports "
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
                 "\t\t\t-D [chanelToChange] [valueToSet]\n";
    std::cout << "\t\t-s --split\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-D [n] [m] -S [thickness ] -T [lineColor] -S [alpha]\n";
    std::cout << "\t\t-q --square\n"
                 "\t\t\tOPTIONS:\n"
                 "\t\t\t-D [coords1] -S [sideSize] -S [lineThickness] -T [lineColor] -S [alpha] -T [fillColor] -S [alpha]\n";

    std::cout << "\tOPTIONS" << std::endl;
    std::cout << "\t\t-i, --input\n"
                 "\t\t\tchoose file to open" << std::endl;
    std::cout << "\t\t-o, --output\n"
                 "\t\t\tchoose file to save result" << std::endl;

    std::cout << "\t\t-S, --single\n"
                 "\t\t\tone integer value" << std::endl;
    std::cout << "\t\t-D, --double\n"
                 "\t\t\tpair of integers as coordinates a point" << std::endl;
    std::cout << "\t\t-T, --triple\n"
                 "\t\t\tthree or four integers for RGB color" << std::endl;
}

void errorMessage(const char* errStr)
{
    if (errStr)
        std::cout << errStr << std::endl;

    std::cout << "Error: wrong usage" << std::endl <<
              "use './Nozdrin_Vasily_cw {-h --help}' "
              "with an operation for available options" << std::endl;
}
