#include "text_func.h"

void delete_duplicates (Text_t *text)
{
    int new_len = 0;
    for (int i = 0; i < text->len-1; i++)
    { if (text->sentences[i])
        for (int j = i+1; j< text->len; j++)
        { if (text->sentences[j])
            if (text->sentences[i]->len == text->sentences[j]->len)
            {
                wchar_t s1[text->sentences[i]->len+1];
                wcscpy(s1, text->sentences[i]->str);
                wchar_t s2[text->sentences[j]->len+1];
                wcscpy(s2, text->sentences[j]->str);
                for(int k = 0; s1[k] ; k++){
                    s1[k] = towlower(s1[k]);
                    s2[k] = towlower(s2[k]);
                }
                if(!snt_str_cmp((void*)(&s1), (void*)(&s2)))
                {
                    free(text->sentences[j]->str);
                    free(text->sentences[j]);
                    text->sentences[j] = NULL;
                }
            }
        }
    }
    /* shift text to remove NULL sentences */
    for (int i = 0; i < text->len; i++)
    {
        if (text->sentences[i])
        {
            if(new_len != i)
            {
                text->sentences[new_len] = text->sentences[i];
                text->sentences[i] = NULL;
            }
            new_len++;
        }
    }
    text->len = new_len;
}

Text_t *anagrams(Text_t *text)
{
    return text;
}

Text_t *cap_sort(Text_t *text)
{
    return text;
}

Text_t *vowels_shift(Text_t *text)
{
    return text;
}

Text_t *find_and_replace(Text_t *text, wchar_t *wstr)
{
    return text;
}
