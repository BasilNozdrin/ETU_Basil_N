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
                /* copy snt[i] to s1 */
                wchar_t s1[text->sentences[i]->len+1];
                wcscpy(s1, text->sentences[i]->str);
                /* copy snt[j] to s2 */
                wchar_t s2[text->sentences[j]->len+1];
                wcscpy(s2, text->sentences[j]->str);

                /* lower both snt */
                for(int k = 0; s1[k] ; k++){
                    s1[k] = towlower(s1[k]);
                    s2[k] = towlower(s2[k]);
                }

                /* delete snt[j] if needed */
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
        if (text->sentences[i])
        {
            if (new_len != i) {
                text->sentences[new_len] = text->sentences[i];
                text->sentences[i] = NULL;
            }
            new_len++;
        }
    text->len = new_len;
}

void print_anagrams(const Text_t *text)
{
    int mask[text->len];
    memset(mask, 0, text->len);
//     for (int i = 0; i < text->len; i++)
//         wprintf(L"%d ", mask[i]);
    for (int i = 0; i < text->len-1; i++)
        if (mask[i] == 0)
        {
            for (int j = i + 1; j < text->len; j++)
                if (check_anagram(text->sentences[i]->str, text->sentences[j]->str))
                {
                    mask[i] = 1;
                    mask[j] = 1;
                }
            for (int j = 0; j < text->len; j++)
                if (mask[j] == 1) {
                    wprintf(L"[%d|%d]:", i, j);
                    print_sentence(*(text->sentences[j]));
                    wprintf(L"\n");
                    mask[j] = -1;
                }
        }
}

void cap_sort(Text_t *text)
{
    qsort(text->sentences, text->len, sizeof(Sentence_t*), cap_cmp);
}

void vowels_shift(Text_t *text)
{
    /*TODO: vowels shift */
    for (int i = 0; i < text->len; i++)
    {
        snt_vowels_shift(text->sentences[i]);
    }
}

void snt_vowels_shift (Sentence_t *snt)
{
    wchar_t *new_str = malloc((snt->len*2)*sizeof(wchar_t));
    int new_len = 0;
    for (int i = 0; snt->str[i]; i++)
    {
        if (wcschr(L"Yy", snt->str[i]))
        {
            new_str[new_len++] = (snt->str[i]+1);
            new_str[new_len++] = (snt->str[i]-24);
            continue;
        }
        if(wcschr(L"AEIOUaeiouАЕЁИОУЫЭаеёиоуыэ", snt->str[i]))
        {
            new_str[new_len++] = (snt->str[i]+1);
            new_str[new_len++] = (snt->str[i]+2);
            continue;
        }
        if (wcschr(L"Юю", snt->str[i]))
        {
            new_str[new_len++] = (snt->str[i]+1);
            new_str[new_len++] = (snt->str[i]-30);
            continue;
        }
        if (wcschr(L"Яя", snt->str[i]))
        {
            new_str[new_len++] = (snt->str[i]-31);
            new_str[new_len++] = (snt->str[i]-30);
            continue;
        }
        new_str[new_len++] = snt->str[i];
    }
    new_str[new_len] = L'\0';
    free(snt->str);
    snt->str = new_str;
    snt->len = new_len;
}

Text_t *find_and_replace(Text_t *text, wchar_t *wstr)
{
    /*TODO find'n'replace */
    return text;
}


int check_anagram(wchar_t *a, wchar_t *b)
{
    int fst[128] = {0}, snd[128] = {0};
    // Calculating frequency of characters of first string
    for (int i = 0; a[i]; i++)
    {
        if (47 < (int)a[i] && (int)a[i] < 58)
            fst[a[i]-L'0'+0]++;
        if (64 < (int)a[i] && (int)a[i] < 91)
            fst[a[i]-L'A'+0+10]++;
        if (96 < (int)a[i] && (int)a[i] < 123)
            fst[a[i]-L'a'+0+10+26]++;
        if (1039 < (int)a[i] && (int)a[i] < 1104)
            fst[a[i]-L'А'+0+10+26+26]++;
    }
    for (int i = 0; b[i]; i++)
    {
        if (47 < (int)b[i] && (int)b[i] < 58)
            snd[b[i]-L'0'+0]++;
        if (64 < (int)b[i] && (int)b[i] < 91)
            snd[b[i]-L'A'+0+10]++;
        if (96 < (int)b[i] && (int)b[i] < 123)
            snd[b[i]-L'a'+0+10+26]++;
        if (1039 < (int)b[i] && (int)b[i] < 1104)
            snd[b[i]-L'А'+0+10+26+26]++;
    }
    // Comparing frequency of characters
    for (int i = 0; i < 128; i++)
    {
        if (fst[i] != snd[i])
        return 0;
    }
    return 1;
}

int cap_cmp(const void* s1, const void* s2)
{
    Sentence_t** snt1 = (Sentence_t**) s1;
    Sentence_t** snt2 = (Sentence_t**) s2;
    return ((*snt1)->cap_c < (*snt2)->cap_c);
}

