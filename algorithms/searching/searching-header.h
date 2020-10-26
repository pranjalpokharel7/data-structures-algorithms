#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int* array, int size){
    for (int i = 0; i < size; i++)
       printf("%d ", array[i]); 
    printf("\n");
}

int* get_array_reverse_sorted_integers(int size){
    int* array = (int *)malloc(size * sizeof(int)); 
    for (int i = 0; i < size; i++)
        array[i] = size - i; 
    return array;
}

int* get_array_sorted_integers(int size){
    int* array = (int *)malloc(size * sizeof(int)); 
    for (int i = 0; i < size; i++)
        array[i] = i; 
    return array;
}


int* get_array_random_integers(int size, int min, int max){
    srand(time(0));
    int* array = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        array[i] = rand() % (max - min + 1) + min;
    return array;  
}

double search_and_measure_time(int* array, int size, 
        int item_to_search, int (*fp)(int*, int, int)){ 
    clock_t start = clock();
    int item_index = (*fp)(array, size, item_to_search);
    clock_t stop = clock();

    if (item_index == -1)
        printf("%d was not found in the array \n", item_to_search);
    else
        printf("%d was found in the array at position %d \n",
                item_to_search, item_index);

    return (double)(stop - start) / CLOCKS_PER_SEC;
}

void cleanup_array(int* array){
    free(array);
}
