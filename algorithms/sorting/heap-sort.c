#include <stdio.h>
#include <stdlib.h>
#include "sorting_header.h"

void max_heapify(int* array, int size, int index){
    int parent = index;
    int left_child = 2*index+1;
    int right_child = 2*index + 2;

    if (left_child< size && array[left_child] > array[parent]) 
        parent = left_child;

    if (right_child < size && array[right_child] > array[parent])
        parent = right_child;

    if (parent != index){
        swap(&array[index], &array[parent]);
        max_heapify(array, size, parent);
    }
}

void heap_sort(int* array, int size){
    // all elements below [size/2 -1] are root nodes
    for (int index = size/2 - 1; index >= 0; index--)
        max_heapify(array, size, index);

    for (int index = size-1; index>0; index--){
        swap(&array[0], &array[index]);
        max_heapify(array, index, 0);
    }
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;
    
    int *array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array, size, heap_sort);
    print_array(array, size);

    printf("Time taken to sort the array is: %lf \n",time_taken);
    cleanup_array(array);
    return 0;
}
