#include "sum_between_negative.h"


int sum_between_negative (int array[], int len){
    int sum = 0;
    int id_last_negative = index_last_negative(array, len);
    for (int i = index_first_negative(array, len); i < id_last_negative; i++){
        sum += abs(array[i]);
    }
    return sum;
}
