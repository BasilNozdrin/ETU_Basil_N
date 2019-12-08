#ifndef TEXT_FUNC_H
#define TEXT_FUNC_H

#include "text.h"

void delete_duplicates (Text_t *text);
void print_anagrams(const Text_t *text);
void cap_sort(Text_t *text);
void vowels_shift(Text_t *text);
void snt_vowels_shift (Sentence_t *snt);
Text_t *find_and_replace(Text_t *text, wchar_t *wstr);
int check_anagram(wchar_t *a, wchar_t *b);
int cap_cmp(const void* s1, const void* s2);

#endif
