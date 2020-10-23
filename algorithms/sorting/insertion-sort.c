#include <stdio.h> 
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

int main(){
    int size = 100000;
    int min_rand = 1, max_rand = 10000;
    int *array = array_random_integers(size, min_rand, max_rand);

    printf("Before sorting: \n");
    print_array(array, size);

    double time_taken = sort_and_measure_time(array,size,insertion_sort);

    printf("After sorting: \n");
    print_array(array, size);
    printf("Time taken to sort the array is : %lf s\n", time_taken);
    
    cleanup_array(array); // run this function before the program ends to deallocate memory 

    return 0;
}
