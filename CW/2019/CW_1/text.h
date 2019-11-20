#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>


#ifndef TEXT_H
#define TEXT_H

typedef struct
{
	wchar_t *str;
	int len, size;
} Sentence;

typedef struct
{
	Sentence **sentences;
	int len, size;
} Text;

Sentence *read_sentence ();
Text *read_text ();
int cmp_text (Text *text1, Text *text2);
int delete_duplicates (Text *text);

#endif

