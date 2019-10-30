#include "sum_before_and_after_negative.h"

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
