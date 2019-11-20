#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "textio.h"
//#include "text_module.h"

int main ()
{
	setlocale(LC_ALL, "");
	Text *text = read_text ();
	for (int i = 0; i < text->len; i++)
	{
		wprintf(L"%ls", (text->sentences[i])->str);
		free((text->sentences[i])->str);
		free(text->sentences[i]);
	}
	free(text->sentences);
	free(text);
	return 0;
	if (delete_duplicates (text))
		return 1;
	char command;
	do
	{
		puts("Hi there! Type number 0-5 to choose an option!");
		puts("0 : to finish the programm");
		puts("1 : show all anagrams in the text");
		puts("2 : to sort sentences of the text by the number of capital letters on each one");
		puts("3 : to replace every vowels with the next vowel by the alphabet order");
		puts("~~~~Tip: 'Я' is replaced by 'А' and 'Z' is replaced by 'A'");
		puts("4 : \"Find & Replace All\" option");
		puts("5 : to show the text");
		char tmp[100];
		gets(tmp);
		command = tmp[0];
		switch (command)
		{
			case '0':
				break;
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			default:
				puts("Oops, you look like you missspelled something! Try again!");
				break;
		}
	} while (command != '0');
	return 0;
}
