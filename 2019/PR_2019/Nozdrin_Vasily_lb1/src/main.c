#include <stdio.h>
#include <stdlib.h>

#define max_len 100

int index_first_negative (int array[], int len);
int index_last_negative (int array[], int len);
int sum_between_negative (int array[], int len);
int sum_before_and_after_negative (int array[], int len);

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


int index_first_negative (int array[], int len){
    for (int i = 0; i < len; i++){
        if (array[i] < 0){
            return i;
        }
    }
    return -1;
}


int index_last_negative (int array[], int len){
    for (int i = len-1; i >= 0; i--){
        if (array[i] < 0){
            return i;
        }
    }
    return -1;
}


int sum_between_negative (int array[], int len){
    int sum = 0;
    int id_last_negative = index_last_negative(array, len);
    for (int i = index_first_negative(array, len); i < id_last_negative; i++){
        sum += abs(array[i]);
    }
    return sum;
}


int sum_before_and_after_negative (int array[], int len){
    int sum = 0;
    for (int i = 0; i < index_first_negative(array, len); i++){
        sum += abs(array[i]);
    }
    for (int i = index_last_negative(array, len); i < len; i++){
        sum += abs(array[i]);
    }
    return sum;
}

