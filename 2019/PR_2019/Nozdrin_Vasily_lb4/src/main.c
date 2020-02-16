#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

#define PRINT

int cmp (const void *a_int, const void *b_int) {
    if ( *(int*)a_int <  *(int*)b_int ) return -1;
    if ( *(int*)a_int == *(int*)b_int ) return 0;
    if ( *(int*)a_int >  *(int*)b_int ) return 1;
    //return *((int*)a_int) < *((int*)b_int);
}

int main() {
    int array[N];
    int *flag;
    clock_t t;
    // read array
    for (int i = 0; i < N; i++)
        scanf("%d", array+i);
    
    // qsort array
    qsort(array, N, sizeof(int), cmp);

    
    // bsearch 0 in array
    int key = 0;
    t = clock(); // save time
    flag = (int*) bsearch (&key, array, N, sizeof(int), cmp);
    t = clock() - t; // print time
    #ifdef PRINT
    printf ("%f\n", ((float)t)/CLOCKS_PER_SEC);
    #endif
    if (flag)
        puts("exists");
    else
        puts("doesn't exist");
    
    
    // brute force search 0 in array 
    flag = NULL;
    t = clock(); //save time
    for (int i = 0; !flag && (i < N); i++)
        if (array[i] == 0)
            flag = array + i;
    t = clock() - t; // print time
    #ifdef PRINT
    printf ("%f\n", ((float)t)/CLOCKS_PER_SEC);
    if (flag)
        puts("exists");
    else
        puts("doesn't exist");
    #endif
    return 0;
}

