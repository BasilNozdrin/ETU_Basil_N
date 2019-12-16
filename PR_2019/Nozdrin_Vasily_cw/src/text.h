#ifndef TEXT_H
#define TEXT_H


/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>


/* define structures */
typedef struct
{
    wchar_t *str;
    int len, size;
    int cap_c;
} Sentence_t;

typedef struct
{
    Sentence_t **sentences;
    int len, size;
} Text_t;


/* read functions */
Sentence_t *read_sentence (FILE * stream);
Text_t *read_text (FILE * stream);

/* print functions */
void print_sentence (Sentence_t snt);
void print_text (Text_t text);

/* comparator functions */
int snt_str_cmp (void* snt1, void* snt2);

#endif
