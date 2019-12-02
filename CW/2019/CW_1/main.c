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
    setlocale (LC_ALL, "");
    fputws(L"Hi there!\nReading text from stdin...\n", stdout);
    
    Text_t *text = read_text ();
    
    delete_duplicates (text);

    wchar_t *tip = L"Type number 0-5 to choose an option!\n0 : to finish the programm\n1 : show all anagrams in the text\n2 : to sort sentences of the text by the number of capital letters on each one\n3 : to replace every vowels with the next vowel by the alphabet order\n~~~~Tip: 'Я' is replaced by 'А' and 'Z' is replaced by 'A'\n4 : \"Find & Replace All\" option\n5 : to show the text\n6 : to show this tip again\n";
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
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '3':
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '4':
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '5':
                print_text(*text);
                fputws(L"Done! Type next command to continue. (6 to show the tip)\n", stdout);
                break;
            case '6':
                fputws(tip, stdout);
                break;
            default:
                fputws(L"Oops, you look like you missspelled something! Try again! Type 6 to show the tip\n", stdout);
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
