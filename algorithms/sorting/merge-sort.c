#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sorting_header.h"

void merge_arrays(int *array, int p, int q, int r){
    int n_left = q-p+1; // compute the length of first half of array
    int n_right = r-q; // compute the length of last half of array
    int* left = malloc((n_left + 1) * sizeof *left);
    int* right = malloc((n_left + 1) * sizeof *right);

    int i,j,k; 
    for (i=0; i<n_left; i++)
        left[i] = array[p+i]; // copy elements from first half of the array
    for (j=0; j<n_right; j++)
        right[j] = array[q+1+j]; // copy elements from the last half of the array

    left[n_left] = INT_MAX; // maximum value inserted at the last index to check if one part is empty 
    right[n_right] = INT_MAX;
    i=j=0;
    k=p;
    for (k=p; k<=r; k++){
        if (left[i] < right[j] && i < n_left){
            array[k] = left[i];
            i++;
        }
        else{
            array[k] = right[j];
            j++;
        }
    } 

    free(left);
    free(right);
}

void merge_sort(int* array, int p, int r){
    if (p<r){
        int q = p + (r-p)/2;
        merge_sort(array,p,q);
        merge_sort(array,q+1,r);
        merge_arrays(array,p,q,r);
    } 
}

void merge_sort_wrapper(int* array, int size){
    merge_sort(array, 0, size-1);
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;
    
    int* array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array,
            size, merge_sort_wrapper);
    print_array(array, size);

    printf("Time taken to sort is : %lf \n", time_taken);
    cleanup_array(array);
    return 0;
}
