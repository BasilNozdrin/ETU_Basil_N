/*
 * На вход программе подается текст, представляющий собой набор предложений с новой строки.
 * Текст заканчивается предложением "Fin."
 * В тексте могут встречаться примеры запуска программ в командной строке Linux.
 * Требуется, используя регулярные выражения, найти только примеры команд в оболочке суперпользователя
 * и вывести на экран пары <имя пользователя> - <имя_команды>.
 * Если предложение содержит какой-то пример команды,
 * то гарантируется, что после нее будет символ переноса строки.
 */ /*
     * Примеры имеют слеующий вид:
     * Сначала идет имя пользователя, состоящее из букв, цифр и символа _
     * Символ @
     * Имя компьютера, состоящее из букв, цифр, символов _ и -
     * Символ : и ~
     * Символ $, если команда запущена в оболочке пользователя
     * и #, если в оболочке суперпользователя. При этом между двоеточием, тильдой и $ или # могут быть пробелы.
     * Пробел
     * Сама команда и символ переноса строки.
     */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

//#define DEBUG

int main () {
    char **text = NULL;
    int text_length = 0, text_buffer_size = 0;
    char *sentence = NULL;
    int sentence_length = 0, sentence_buffer_size = 0;
    char c;
    /* read a text */
    do {
        /* alloc or realloc memory for the text (char* array) */
        if (text_length + 2 >= text_buffer_size) {
            text_buffer_size += 16;
            char **tmp = (char**) realloc (text, sizeof(char*)*text_buffer_size);
            if (!tmp)
                break;
            text = tmp;
        }
        
        /* read a sentence */
        sentence = NULL;
        sentence_length = 0; sentence_buffer_size = 0;
        c = getc(stdin);
        while (c != '\n' && c != EOF) {
            /* alloc or realloc memory for the sentence (char array) */
            if (sentence_length + 2 >= sentence_buffer_size) {
                sentence_buffer_size += 32;
                char *tmp_sentence = (char*) realloc (sentence, sizeof(char)*sentence_buffer_size);
                if (!tmp_sentence)
                    break;
                sentence = tmp_sentence;
            }
            sentence[sentence_length++] = c;
            sentence[sentence_length] = '\0';
            c = getc(stdin);
        }
        
        text[text_length++] = sentence;
    } while (strcmp ("Fin.", text[text_length-1]) != 0);
    
#ifdef DEBUG
    for (int i = 0; i < text_length - 1; i++)
        printf("%s\n", text[i]);
#endif
    
    /* reg expr stuff shuold be placed below */
    char *regexString = "^(.* )?([A-Za-z0-9_]+)@([A-Za-z0-9_-]+): ?~ ?([#]) (.+)$";
    // Groups :          /.1/ /......2....../ /.......3....../      /...4../ /........5......../    In total : 6
    //                                                                \\$ could be there, but I don't whant to add 'if' for this case          
    size_t maxGroups = 6;
    
    regex_t regexCompiled;
    regmatch_t groupArray[maxGroups];
    
    // Compile regular expression
    if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
    {
        printf("Regex compilation error\n");
        return 0;
    }
    
    // Match 
    int match_result;
    for (int i = 0; i < text_length - 1; i++) // because of the last sentence is "Fin.", we can skip it
    {
        if (regexec(&regexCompiled, text[i], maxGroups, groupArray, 0) == 0)
        {
#ifndef DEBUG
            if (groupArray[2].rm_so == -1)
                    break;
            if (groupArray[5].rm_so == -1)
                    break;
            for (int k = groupArray[2].rm_so; k < groupArray[2].rm_eo; k++)
                printf("%c",text[i][k]);
            printf(" - ");
            for (int k = groupArray[5].rm_so; k < groupArray[5].rm_eo; k++)
                printf("%c",text[i][k]);
            printf("\n");
#endif
#ifdef DEBUG
            for (int j = 1; j < maxGroups; j++)
            {
                if (groupArray[j].rm_so == -1)
                {
                    printf("No %2d group\n", j);
                    if (j == 1)
                        continue;
                    break;
                }
                /* ^(.*) ([A-Za-z0-9_]+)@([A-Za-z0-9_-]+): ?~ ?([\$#]) ([\w\s]+)$
                 * user_name = group[2]     computer_name = group[3]        sudo if group[4] == '#'     command = group[5]
                 */
                printf("Group %d: [%2d-%2d]: ", j, groupArray[j].rm_so, groupArray[j].rm_eo);
                for(int k = groupArray[j].rm_so; k < groupArray[j].rm_eo; k++)
                    printf("%c",text[i][k]);
                printf("\n");
            }
            printf("-----------------------------------\n");
#endif
        }
#ifdef DEBUG
        else {
            printf("NOТ matched!\n");
            printf("-----------------------------------\n");
        }
#endif
    }
    
    // Free memory
    for (int i = 0; i < text_length; i++)
    {
        free (text[i]);
    }
    free (text);
    regfree(&regexCompiled);
    
    return 0;
}
