#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>
#include <dirent.h>
#include <sys/types.h>

typedef struct {
    char *letters;
    int len;
    char **routes;
} myDict;

int isValid(char *filename);
void save (const char *route, myDict *dict);
void listDir (char *startDir, myDict *dict);

int main (int argc, char **argv, char **env)
{

    //if (argc != 2) { printf ("use ./prog <path>\n"); return 0; }
    FILE *result = fopen ("result.txt", "w");

    char *letters = (char*) malloc (NAME_MAX * sizeof(char));
    scanf("%s", letters);
    char **routes = (char**) calloc (strlen(letters), sizeof(char*));
    myDict dict = {letters, strlen(letters), routes};

    listDir ("tmp"/*argv[1]*/, &dict);

    int len = strlen(dict.letters);
    for (int i = 0; i < len; i++)
    {
        fprintf(result, "%s\n", routes[i]? routes[i]: "NULL");
    }

    fclose(result);
    return 0;
}

void save (const char *route, myDict *dict)
{
    char c = route[strlen(route)-5];
    //printf("[%c]%s\n", c, route);
    for (int i = 0; i < dict->len; i++)
        if (dict->letters[i] == c)
        {
            dict->routes[i] = malloc ((strlen(route)+1) * sizeof(char));
            strcpy(dict->routes[i], route);
            return;
        }
}

void listDir (char *startDir, myDict *dict)
{
    char *regexp = "^[[:alpha:]]\\.txt$";
    regex_t regexComp;
    if (regcomp (&regexComp, regexp, REG_EXTENDED)) { perror("regexCompile"); return exit(1); }

    char nextDir[NAME_MAX]={0};
    strcpy(nextDir, startDir);
    DIR *dir = opendir(startDir);
    struct dirent *entry;

    if (!dir) { perror("diropen"); exit(1); }
    while ((entry = readdir (dir)))
    {
        if (!strcmp(entry->d_name, ".")||!strcmp(entry->d_name, ".."))
            continue;

        if (entry->d_type == DT_DIR)
        {
            int len = strlen (nextDir);
            strcat (nextDir, "/");
            strcat (nextDir, entry->d_name);
            listDir (nextDir, dict);
            nextDir[len] = '\0';
        }

        if (entry->d_type == DT_REG && (regexec(&regexComp, entry->d_name, 0, NULL, 0) == 0)) // TODO
        {
            int len = strlen (nextDir);
            strcat (nextDir, "/");
            strcat (nextDir, entry->d_name);
            save (nextDir, dict);
            nextDir[len] = '\0';
        }
    }
    closedir(dir);

    regfree(&regexComp);
}

/*
 * Дана некоторая корневая директория,
 * в которой может находиться некоторое количество папок, в том числе вложенных.
 * 
 * В этих папках хранятся некоторые текстовые файлы, имеющие имя вида <filename>.txt.
 * В качестве имени файла используется символ латинского алфавита.
 * На вход программе подается строка.
 * Требуется найти и вывести последовательность полных путей файлов, имена которых образуют эту строку.
 * 
 * Входная строка:
 * HeLlO
 * Правильный ответ:
 * hello_world_test/asdfgh/mkoipu/H.txt
 * hello_world_test/qwerty/e.txt
 * hello_world_test/qwerty/qwert/L.txt
 * hello_world_test/asdfgh/l.txt
 * hello_world_test/asdfgh/O.txt
 * 
 * ! Регистрозависимость
 * ! Могут встречаться файлы, в имени которых есть несколько букв и эти файлы использовать нельзя.
 * ! Одна буква может встречаться один раз.
 * 
 * Ваше решение должно находиться в директории /home/box, файл с решением должен называться solution.c.
 * 
 * Результат работы программы должен быть записан в файл result.txt.
 * Ваша программа должна обрабатывать директорию, которая называется tmp.
 */

// gcc solution.c && ./a.out >result.txt && rm ./a.out
