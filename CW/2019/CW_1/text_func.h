#ifndef TEXT_FUNC_H
#define TEXT_FUNC_H

#include "text.h"

void delete_duplicates (Text_t *text);
Text_t *anagrams(Text_t *text);
Text_t *cap_sort(Text_t *text);
Text_t *vowels_shift(Text_t *text);
Text_t *find_and_replace(Text_t *text, wchar_t *wstr);


#endif
