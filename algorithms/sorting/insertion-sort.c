#include <stdio.h> 
#include <stdlib.h>
#include "sorting_header.h"

void insertion_sort(int* array, int size){
    int j, key;
    for (int i = 1; i < size; i++){
        j = i - 1;
        key = array[i];
        while (j >=0 && array[j] > key){
            array[j+1] = array[j]; 
            j--;
        }
        array[j+1] = key;
    } 
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;

    int *array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array,size,insertion_sort);
    print_array(array, size);
    
    printf("Time taken to sort the array is : %lf s\n", time_taken);
    cleanup_array(array); // run this function before the program ends to deallocate memory 
    return 0;
}
