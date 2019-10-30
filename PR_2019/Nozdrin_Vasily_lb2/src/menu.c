#include <stdio.h>
#include <stdlib.h>
#include "index_first_negative.h"
#include "index_last_negative.h"
#include "sum_between_negative.h"
#include "sum_before_and_after_negative.h"


#define max_len 100


int main(){
    char temp, command;
    scanf("%c%c", &command, &temp);
    if (temp != ' ') {
        puts("Данные некорректны\n");
        return 0;
    }

    int len = 0;
    int values[max_len];
    do {
        scanf("%d%c", &values[len], &temp);
        len++;
    } while(temp != '\n');
    switch(command) {
        case '0':
            printf("%d\n",index_first_negative(values, len));
            break;
        case '1':
            printf("%d\n",index_last_negative(values, len));
            break;
        case '2':
            printf("%d\n",sum_between_negative(values, len));
            break;
        case '3':
            printf("%d\n",sum_before_and_after_negative(values, len));
            break;
        default:
            puts("Данные некорректны");
            break;
    }

    return 0;
}
