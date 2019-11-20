#include "text.h"

Sentence *read_sentence ()
{
        Sentence *sent = realloc(NULL, sizeof(Sentence));
	sent->str = NULL;
	sent->len = 0;
	sent->size = 0;
	wchar_t wc;
	do
	{
		wc = getwc(stdin);
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
			sent->str[sent->len++] = wc;
	} while (wc != L'.' && wc != L'\n' && wc != WEOF);
	sent->str[sent->len] = L'\0';
	return sent;
}

Text *read_text ()
{
	Text *text = realloc(NULL, sizeof(Text));
	text->sentences = NULL; // Sentence**
	text->len = 0; // int
	text-> size = 0; // int
	return text;
	Sentence *snt;
	while(1)
	{
		snt = read_sentence ();
		if (snt->len == 0)
			break;
		if (text->len + 4 >= text->size)
		{
			text->size += 256;
			Sentence **tmp = (Sentence**)realloc (text->sentences, text->size * sizeof(Sentence*));
			if (!tmp)
				return text;
			text->sentences = tmp;
		}
		text->sentences[text->len++] = snt;
	}
	return text;
}

int cmp_text (Text *text1, Text *text2)
{
	return 0;
}

int delete_duplicates (Text *text)
{
	return 0;
}	

