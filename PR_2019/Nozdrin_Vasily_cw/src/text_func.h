#ifndef TEXT_FUNC_H
#define TEXT_FUNC_H

#include "text.h"

void delete_duplicates (Text_t *text);
void print_anagrams (const Text_t *text);
void cap_sort (Text_t *text);
void vowels_shift (Text_t *text);
void snt_vowels_shift (Sentence_t *snt);
void snt_find_and_replace (Sentence_t *snt, wchar_t *old, wchar_t *new);
int check_anagram (wchar_t *a, wchar_t *b);
int cap_cmp (const void* s1, const void* s2);

#endif
