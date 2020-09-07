#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *end_word = "Dragon flew away!";
    const char *curse_word = "555";
    
    char **text = NULL;
    int text_len = 0, text_buffer = 0;
    
    char *next_sentence = NULL, *end_pointer = NULL, *curse_pointer = NULL;
    int sentence_len = 0, sentence_buffer = 0;
    char next_char;
    
    int number_sentences_before = 0, number_sentences_after = 0;
    
    while(1)
    {
        if (text_len+2 >= text_buffer)
        {
            text_buffer += 100;
            text = realloc(text, (text_buffer) * sizeof(char*));
        }
        
        while(1)
        {
            /* read char w/o begin spaces */
            next_char = getc(stdin);
            if (sentence_len == 0 && (next_char == ' ' || next_char == '\t' ))
                continue;
            
            /* expand memory and write char */
            if (sentence_len+2 >= sentence_buffer)
            {
                sentence_buffer += 100;
                next_sentence = realloc(next_sentence, (sentence_buffer) * sizeof(char));
            }
            next_sentence[sentence_len] = next_char;
            next_sentence[sentence_len+1] = '\0';
            sentence_len++;
            
            /* end of next_sentence */
            if ((next_char == '.')||(next_char == ';')||(next_char == '?')||(next_char == EOF))
            {
                if (strlen(next_sentence) >= strlen(end_word))
                    end_pointer = strstr(next_sentence, end_word);
                if (end_pointer)
                {
                    *(end_pointer + sizeof(char) * strlen(end_word)) = '\0';
                }
                else
                {
                    number_sentences_before++;
                }
            /**/
            /**/
                if (sentence_len-1 == strlen(curse_word))
                    curse_pointer = strstr(next_sentence, curse_word);
                if (sentence_len > strlen(curse_word))
                {
                    //strtok()
                }
                
                if (sentence_len < strlen(curse_word) || !curse_pointer)
                {
                    text[text_len] = calloc(strlen(next_sentence), sizeof(char));
                    strcpy(text[text_len], next_sentence);
                    text_len++;
                    if (!end_pointer)
                        number_sentences_after++;
                }
                /* free memory and reset length and buffer */
                free(next_sentence);
                next_sentence = NULL;
                sentence_len = 0;
                sentence_buffer = 0;
                break;
            }
        }
        
        /* exit condition */
        if(end_pointer)
            break;
    };
    
    /* print result */
    for(int i = 0; i < text_len; i++)
    {
        printf("%s\n", text[i]);
        free(text[i]);
        text[i] = NULL;
    }
    free(text);
    printf("Количество предложений до %d и количество предложений после %d\n", number_sentences_before, number_sentences_after);
    return 0;
}