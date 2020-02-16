#include "text.h"


Sentence_t *read_sentence (FILE * stream)
{
    Sentence_t *sent = realloc (NULL, sizeof(Sentence_t));
    sent->str = NULL; // wchar_t
    sent->len = 0; // int
    sent->size = 0; // int
    sent->cap_c = 0; // int
    wchar_t wc;
    do
    {
        wc = getwc (stream);
        if (sent-> len == 0 && wc == WEOF)
            return NULL;
        if (sent->len + 4 >= sent->size)
        {    
            sent->size += 64;
            wchar_t *tmp = (wchar_t*)realloc (sent->str, sent->size * sizeof(wchar_t));
            if (!tmp)
            {
                if (sent->len == 0)
                    return NULL;
                else
                {
                    sent->str[sent->len] = L'\0';
                    return sent;
                }
            }
            sent->str = tmp;
        }
        if (wc)
        {
            if (iswupper (wc))
                sent->cap_c++;
            sent->str[sent->len++] = wc;
        }
    } while (wc != L'.' && wc != L'\n' && wc != WEOF);
    sent->str[sent->len] = L'\0';
    return sent;
}


Text_t *read_text (FILE * stream)
{
    Text_t *text = realloc(NULL, sizeof(Text_t));
    text->sentences = NULL; // Sentence**
    text->len = 0; // int
    text-> size = 0; // int
    Sentence_t *snt;
    while ((snt = read_sentence (stream)))
    {
        if (text->len + 4 >= text->size)
        {
            text->size += 256;
            Sentence_t **tmp = (Sentence_t**)realloc (text->sentences, text->size * sizeof(Sentence_t*));
            if (!tmp)
                return text;
            text->sentences = tmp;
        }
        text->sentences[text->len++] = snt;
    }
    return text;
}

void print_sentence (Sentence_t snt)
{
    wprintf (L"%ls", snt.str);
}

void print_text (Text_t text)
{
    wprintf(L"~~~~~~~Text~~~~~~~\n");
    for(int i = 0; i < text.len; i++)
        wprintf(L"%ls", text.sentences[i]->str);
    wprintf(L"\n~~~~~~~~~~~~~~~~~~\n");
}

int snt_str_cmp (void* snt1, void* snt2)
{
    wchar_t *p1 = (wchar_t *)snt1;
    wchar_t *p2 = (wchar_t *)snt2;

    while ( *p1 && *p1 == *p2 ) {p1++; p2++;}
    return (*p1 > *p2) - (*p2 > *p1);
}
