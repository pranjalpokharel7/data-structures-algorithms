#include <stdio.h>
#include <stdlib.h>
#include "sorting_header.h"

void counting_sort(int* array, int size, int min, int max){
    int size_count_array = max - min + 1;
    int* count_array = (int *)malloc((sizeof *count_array) * size_count_array);
    int* output = (int *)malloc((sizeof *output) * size);
    int i;
    for (i = 0; i < size_count_array; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;
   
    for (i = 1; i < size_count_array; i++)
        count_array[i] += count_array[i-1];
    
    for (i = size_count_array-1; i >= 1; i--)
        count_array[i] = count_array[i-1];
    
    count_array[0] = 0;

    int current_number, new_position; 
    for (i = 0; i < size; i++){
        current_number = array[i];
        new_position = count_array[current_number]; 
        output[new_position] = current_number;
        count_array[current_number]++;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(count_array);
    free(output);
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 9; 
    // taking small random space for counting sort because that's when it works best

    int* array = array_random_integers(size, min_rand, max_rand);
    
    print_array(array, size);
    counting_sort(array, size, min_rand, max_rand);
    print_array(array, size);

    cleanup_array(array);
    return 0;
}
