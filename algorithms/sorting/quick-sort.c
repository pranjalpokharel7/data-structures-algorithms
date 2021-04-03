#include <stdio.h>
#include <stdlib.h>
#include "sorting_header.h"

// we choose the first element of the array as the pivot element

int partition_array(int* array, int l, int r){
    int pivot = array[l];
    int j = l;
    for (int i = l+1; i <= r; i++){
        if (array[i] <= pivot){
            j++;
            swap(&array[i], &array[j]);
        } 
    }
    swap(&array[l], &array[j]);
    return j;
}

void quick_sort(int* array, int l, int r){
    if (l >= r)
        return;
    int m = partition_array(array, l, r);
    quick_sort(array, l, m-1);
    quick_sort(array, m+1, r);
}

void quick_sort_wrapper(int* array, int size){
    quick_sort(array, 0, size-1);
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;

    int *array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array, size, quick_sort_wrapper);
    print_array(array, size);

    printf("Time taken to sort is: %lf \n",time_taken);
    cleanup_array(array);
    return 0;
}
