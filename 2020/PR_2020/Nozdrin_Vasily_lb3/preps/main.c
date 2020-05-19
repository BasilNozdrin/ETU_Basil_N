#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define DEBUG


int main (int argc, char **argv, char **env)
{
    if (argc != 3) { printf ("use ./run <path> <option>\n"); return 0; }
#ifdef DEBUG
    printf("\nGoing through dir %s\nOption %s\n", argv[1], argv[2]);
#endif
    switch (argv[2][0])
    {
        case '1':
            listDir1 (argv[1]);
            break;
        case '2':
            listDir2 (argv[1]);
            break;
        case '3':
            listDir3 (argv[1]);
            break;
        default:
            printf ("wrong option. use 1, 2 or 3\n"); return 0;
    }
    return 0;
}
