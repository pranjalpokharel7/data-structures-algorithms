#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sorting_header.h"

/*
 * For shell shot, selecting the initial gap is cruical in reducing time complexity for worst case scenario. 
 * In the original shell short, the interval is taken at [N/2^k] with N being the size of the array.
 * Here, we take intervals at 2^k-1 i.e. 1,3,7,15,... as per Hibbard's proposal in 1963. 
 * This reduces time complexity inworst case scenario to O(N ^ 1.5) compared to O(N^2) in the original shell sort.
 * */

void shell_sort(int *array, int size){
    int i,j,key;
    int k = floor(log(size+1)/log(2));
    int step = pow(2,k)-1;
    while (step >= 1){
        for (i = step; i < size; i++){
            j = i-step;
            key = array[i];
            while (j >= 0 && array[j] > key){
                array[j+step] = array[j];  
                j -= step;
            }
            array[j+step] = key;
        }
        k--;
        step = pow(2,k)-1;
    }
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;

    int *array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array,size,shell_sort);
    print_array(array, size);
    
    printf("Time taken to sort the array is : %lf s\n", time_taken);
    cleanup_array(array); // run this function before the program ends to deallocate memory 
    return 0;
}
