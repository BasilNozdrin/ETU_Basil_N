#include "functions.h"


#define DEBUG

void listDir1 (char *startDir)
{
    char *regexp = "^([[:alpha:]]).*$"; size_t maxGroups = 2;
    regex_t regexComp; regmatch_t groupArray[maxGroups];
    if (regcomp (&regexComp, regexp, REG_EXTENDED)) { perror("regexCompile"); return exit(1); }

    char curDir[NAME_MAX]= { 0 };
    strcpy(curDir, startDir);

    void listDir (char *curDir)
    {
        DIR *dir = opendir(curDir);
        struct dirent *entry;
        if (!dir) { perror("diropen"); exit(1); }

        while ((entry = readdir(dir))) {
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
                continue;

            if (entry->d_type == DT_DIR)
            {
                if (strlen(entry->d_name) == 1)
                    continue;
                int len = strlen(curDir);
                strcat(curDir, "/");
                strcat(curDir, entry->d_name);
                listDir(curDir);
                remove(curDir);
#ifdef DEBUG
                printf("rm %s\n", curDir);
#endif
                curDir[len] = '\0';
            }

            if (entry->d_type == DT_REG)
            {
                if (regexec(&regexComp, entry->d_name, maxGroups, groupArray, 0) == 0)
                {
                    char newPath[NAME_MAX] = {0};
                    strcpy(newPath, startDir); strcat(newPath, "/");
                    char folderName[3]; // folderName == "f/"
                    folderName[0] = entry->d_name[groupArray[1].rm_so];
                    folderName[1] = '/'; folderName[2] = '\0';
                    strcat(newPath, folderName);
                    // create folder if it doesn't exist
                    struct stat st = {0};
                    if (stat(newPath, &st) == -1) { mkdir(newPath, 0700); }
                    // mv file to the new folder
                    int len = strlen(curDir);
                    strcat(curDir, "/");
                    strcat(curDir, entry->d_name);
                    strcat(newPath, entry->d_name);
#ifdef DEBUG
                    printf("mv\t%s\t%s\n", curDir, newPath);
#endif
                    rename(curDir, newPath);
                    curDir[len] = '\0';
                } else {
                    int len = strlen(curDir);
                    strcat(curDir, "/");
                    strcat(curDir, entry->d_name);
                    remove (curDir);
                    curDir[len] = '\0';
                }
            }
        }
        closedir(dir);
    }

    listDir (curDir);

    regfree(&regexComp);
}

void listDir2 (char *startDir)
{
    char *regexp = "^([[:alpha:]]).*([[:digit:]]).*\\.[[:alnum:]]+$"; size_t maxGroups = 3;
    regex_t regexComp; regmatch_t groupArray[maxGroups];
    if (regcomp (&regexComp, regexp, REG_EXTENDED)) { perror("regexCompile"); return exit(1); }

    char curDir[NAME_MAX]= { 0 };
    strcpy(curDir, startDir);

    void listDir (char *curDir)
    {
        DIR *dir = opendir(curDir);
        struct dirent *entry;
        if (!dir) { perror("diropen"); exit(1); }

        while ((entry = readdir (dir)))
            {
                if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
                    continue;

                if (entry->d_type == DT_DIR) {
                    if (strlen(entry->d_name) == 2)
                        continue;
                    int len = strlen(curDir);
                    strcat(curDir, "/");
                    strcat(curDir, entry->d_name);
                    listDir(curDir);
                    remove(curDir);
#ifdef DEBUG
                    printf("rm %s\n", curDir);
#endif
                    curDir[len] = '\0';
                }

                if (entry->d_type == DT_REG) {
                    if (regexec(&regexComp, entry->d_name, maxGroups, groupArray, 0) == 0) {
                        char newPath[NAME_MAX] = {0};
                        strcpy(newPath, startDir); strcat(newPath, "/");
                        char folderName[4]; // folderName == "f1/"
                        folderName[0] = entry->d_name[groupArray[1].rm_so];
                        folderName[1] = entry->d_name[groupArray[2].rm_so];
                        folderName[2] = '/'; folderName[3] = '\0';
                        strcat(newPath, folderName);
                        // mkdir
                        struct stat st = {0};
                        if (stat(newPath, &st) == -1) { mkdir(newPath, 0700); }
                        // mv file
                        int len = strlen(curDir);
                        strcat(curDir, "/");
                        strcat(curDir, entry->d_name);
                        strcat(newPath, entry->d_name);
#ifdef DEBUG
                        printf("mv %s %s\n", curDir, newPath);
#endif
                        rename(curDir, newPath);
                        curDir[len] = '\0';
                    } else {
                        int len = strlen(curDir);
                        strcat(curDir, "/");
                        strcat(curDir, entry->d_name);
                        remove (curDir);
                        curDir[len] = '\0';
                    }
                }
            }
        closedir(dir);
    };

    listDir (curDir);

    regfree(&regexComp);
}

void listDir3 (char *startDir)
{
    printf("Enter banned word: ");
    char banned[NAME_MAX] = { 0 };
    fgets(banned, NAME_MAX, stdin);
    *strchr(banned, '\n') = '\0';
#ifdef DEBUG
    printf("word is |%s|\n", banned);
#endif
    char *regexp = "^(.*)(\\.[[:alnum:]]+)$";
    size_t maxGroups = 3;
    regex_t regexComp; regmatch_t groupArray[maxGroups];
    if (regcomp (&regexComp, regexp, REG_EXTENDED)) { perror("regexCompile"); return exit(1); }

    char curDir[NAME_MAX] = { 0 };
    strcpy(curDir, startDir);

    void listDir (char *curDir)
    {
        DIR *dir = opendir(curDir);
        struct dirent *entry;
        if (!dir) { perror("diropen"); exit(1); }

        while ((entry = readdir (dir)))
        {
            if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
                continue;

            if (entry->d_type == DT_DIR) {
                int len = strlen(curDir);
                strcat(curDir, "/");
                strcat(curDir, entry->d_name);
                listDir(curDir);
                curDir[len] = '\0';
            }

            if (entry->d_type == DT_REG) {
                if (regexec(&regexComp, entry->d_name, maxGroups, groupArray, 0) == 0) {
                    if (groupArray[1].rm_so == -1)
                        continue;
                    int ban_l = strlen(banned);
                    for (int i = ban_l-1; i >= 0; i--)
                    {
                        if (banned[i] != entry->d_name[groupArray[1].rm_eo-ban_l+i])
                            break;
                        if (i == 0)
                        {
                            //delete file
                            int len = strlen(curDir);
                            strcat(curDir, "/");
                            strcat(curDir, entry->d_name);
#ifdef DEBUG
                            printf("rm %s\n", curDir);
#endif
                            remove (curDir);
                            curDir[len] = '\0';
                        }
                    }
                }
            }
        }
        closedir(dir);
    };

    listDir (curDir);

    regfree(&regexComp);
}
