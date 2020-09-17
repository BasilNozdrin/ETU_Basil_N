#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int addOvf(int a, int b) {
    long long int result = a + b;
    if ((a > 0 && b > 0 && result < 0)
    ||(a < 0 && b < 0 && result > 0))
        perror ("Int overflow");
    return result;
}

long long int mulOvf(int a, int b) {
    if (a == 0 || b == 0)
        return 0;

    long long int result = a * b;
    if (a == result / b)
        return result;
    else
        perror ("Int overflow");
}

long long int number(char* str) {
    int len = strlen(str);
    long long int result = 0;
    while (len) {
        result = mulOvf(result, 10);
        result = addOvf(result, (int) str[--len] - '0');
    }
    return result;
}

long long int eval(char* str) {
    char* operator = NULL;

    operator = strchr(str, '+');
    if (operator) {
        *(operator++) = '\0';
        return addOvf(eval(str), eval(operator));
    }

    operator = strchr(str, '-');
    if (operator) {
        *(operator++) = '\0';
        return addOvf(eval(str), -eval(operator));
    }

    operator = strchr(str, '*');
    if (operator) {
        *(operator++) = '\0';
        return mulOvf(eval(str), eval(operator));
    }
    
    return number(str);
}

int main () {
    FILE *pFile;
    char* str = malloc(sizeof(char)*201);

    pFile = fopen("input.txt", "r");
    if (pFile == NULL) {
        perror ("Error opening file");
    } else {
        while (fgets(str, 200, pFile)) {
            char* tmp = strchr(str, '\n');
            if (tmp) {*tmp='\0';};
            printf("%s", str);
            printf(" = %lld\n", eval(str));
        };
    };
    fclose(pFile);
    return 0;
}


/* 10. Построить синтаксический анализатор для определяемого далее понятия константное_выражение.
 * константное_выражение::=ряд_цифр| константное_выражение знак_операции константное_выражение
 * знак_операции::=+ | − | *
 * ряд_цифр::=цифра | цифра ряд_цифр
 * 
 * 11. Написать программу, которая по заданному (см. предыдущее задание)
 * константному_выражению вычисляет его значение либо сообщает о переполнении
 * (превышении заданного значения) в процессе вычислений.
 */
