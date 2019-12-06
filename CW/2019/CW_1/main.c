#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>
#include "text.h"
#include "text_func.h"

int main ()
{
    FILE *pFile;
    Text_t *text;
    setlocale (LC_ALL, "");

    /* READ TEXT BEGIN */
    fputws(L"Hi there!\nEnter filename with your text (not longer than 100):\n", stdout);
    wchar_t wfile_path[100];
    char file_path[100];

    while(1) {
        fgetws(wfile_path, 100, stdin);

        if (!wcstombs(file_path, wfile_path, sizeof(file_path)))
        {
            fputws(L"Something went wrong... Try again!\n", stdout);
            continue;
        }

        for (int i = 0; file_path[i]; i++)
        {   if (file_path[i] == '\n'){
                file_path[i] = '\0';
                break;
        }}
        pFile = fopen(file_path, "r");
        if (pFile) {
            text = read_text(pFile);
            fclose(pFile);
            break;
        }
        fputws(L"Something went wrong... Try again!\n", stdout);
    }
    /* READ TEXT END */

    delete_duplicates (text);

    wchar_t *tip = L"Type number 0-5 to choose an option!\n0 : to finish the program\n1 : show all anagrams in the text\n2 : to sort sentences of the text by the number of capital letters on each one\n3 : to replace every vowels with the next vowel by the alphabet order\n~~~~Tip: 'Я' is replaced by 'А' and 'Z' is replaced by 'A'\n4 : \"Find & Replace All\" option\n5 : to show the text\n6 : to show this tip again\n";
    fputws(tip, stdout);

    char command;
    do
    {
        
        wchar_t tmp[100];
        fgetws(tmp, 100, stdin);
        command = tmp[0];
        switch (command)
        {
            case '0':
                fputws(L"Bye!\n", stdout);
                break;
            case '1':
                print_anagrams(text);
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '2':
                cap_sort(text);
                /*TODO*/
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '3':
                /*TODO*/
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '4':
                /*TODO*/
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '5':
                /*TODO*/
                print_text(*text);
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '6':
                fputws(tip, stdout);
                break;
            default:
                fputws(L"Oops, you look like you misspelled something! Try again! Type 6 to show the tip\n", stdout);
                break;
        }
    } while (command != '0');
    for (int i = 0; i < text->len; i++)
    {
        free ((text->sentences[i])->str);
        free (text->sentences[i]);
    }
    free(text->sentences);
    free(text);
    return 0;
}
