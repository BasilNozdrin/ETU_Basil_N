#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <dirent.h>

/* struct dirent {
 *      ino_t          d_ino;       // inode number
 *      off_t          d_off;       // offset to the next dirent
 *      unsigned short d_reclen;    // length of this record
 *      unsigned char  d_type;      // type of file; not supported by all file system types
 *      char           d_name[256]; // filename
 * };
 */


#define WORK_DIR "./tmp/"

void count(char *dir, int levels, int *filecount, int *dircount) {
    struct dirent *dp;
    DIR *fd;

    if ((fd=opendir(dir))==NULL) {
        fprintf(stderr, "count: can't open %s\ncount stopped.", dir);
        exit(0);
    }

    while((dp = readdir(fd))!=NULL){
        if(!strcmp(dp->d_name, ".")||!strcmp(dp->d_name, ".."))
            continue;
        if(dp->d_type==DT_REG){ /* Regular file */
            (*filecount)++;
        }
        if(dp->d_type==DT_DIR){ /* Directory */
            (*dircount)++;
            if(levels>0){
                count(dp->d_name,levels-1,filecount,dircount);
            }
        }
    }
    closedir(fd);
}

void listDir(char* path){
    DIR* dir;
    struct dirent *ent;
    if((dir=opendir(path)) != NULL){
        while (( ent = readdir(dir)) != NULL){
            if(ent->d_type == DT_DIR && strcmp(ent->d_name, ".") != 0  && strcmp(ent->d_name, "..") != 0){
                printf("%s\n", ent->d_name);
                /**/
                listDir(/*path + / + */ent->d_name);
            }
        }
        closedir(dir);
    }
}

int main ()
{
    //printf("DT_DIR:%d\n", DT_DIR);
    //return 0;

    DIR *dir = opendir(WORK_DIR);
    struct dirent *entry;

    if (!dir) {
        perror("diropen");
        exit(1);
    };

    while ((entry = readdir(dir)) != NULL) {
        if(!strcmp(entry->d_name, ".")||!strcmp(entry->d_name, ".."))
            continue;
//        if(entry->d_type == DT_REG){ (*filecount)++;}
//        if(entry->d_type == DT_DIR){ (*dircount)++; if(levels>0) { count(entry->d_name,levels-1,filecount,dircount); }}
        
        printf("%lu - %s [%d] %d\n",
                entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
    };

    closedir(dir);
    return 0;
};



/*
 * Дана некоторая корневая директория,
 * в которой может находиться некоторое количество папок,
 * в том числе вложенных.
 * 
 * В этих папках хранятся некоторые текстовые файлы,
 * имеющие имя вида <filename>.txt.
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
 * Ваше решение должно находиться в директории /home/box,
 * файл с решением должен называться solution.c.
 * 
 * Результат работы программы должен быть записан в файл result.txt.
 * Ваша программа должна обрабатывать директорию, которая называется tmp.
 */

// gcc solution.c && ./a.out >result.txt && rm ./a.out
