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
    
    for (int i = 0; i < text_length - 1; i++)
        printf("%s\n", text[i]);
    
    /* reg expr stuff shuold be placed below */
    regex_t regex;
    int return_value;
    int match_result;
    return_value = regcomp(&regex, ".* [A-Za-z0-9_]\+@", 0);
    // ^(.*) ([A-Za-z0-9_]+)@([A-Za-z0-9_-]+): ?~ ?([#]) ([\w\s]+)$
    if (return_value == 0)
        for (int i = 0; i < text_length - 1; i++) // because of the last sentence is "Fin.", we can skip it
        {
            match_result = regexec(&regex, text[i], 0, NULL, 0);
            printf("Match reult %d: %d\n", i, match_result);
        }
    else
        printf("Compilation error.");
    
        
    /*
     * ^(.*) ([A-Za-z0-9_]+)@([A-Za-z0-9_-]+): ?~ ?([\$#]) ([\w\s]+)$
     * 
     * ^(.*) ([A-Za-z0-9_]+)@([A-Za-z0-9_-]+): ?~ ?([#]) ([\w\s]+)$
     * 
     * user_name = group[2]
     * computer_name = group[3]
     * command is stared as sudo if group[4] = # else group[4] = $ and we have to ignore it
     * command = group[5]
     */
        // TODO
    return 0;
}

