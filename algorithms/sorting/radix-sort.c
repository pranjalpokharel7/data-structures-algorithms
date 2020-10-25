#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "sorting_header.h"

int number_of_digits(int num){
    int count = 0;
    while (num){
        count++;
        num /= 10;
    }
    return count;
}

void radix_sort(int* array, int size){
    // loop to find out the largest element in the array
    int max_num = INT_MIN; 
    for (int i = 0; i < size; i++){
        if (array[i] > max_num)
            max_num = array[i];
    }

    int number_of_passes = number_of_digits(max_num); 
    int* radix_bucket = (int *)malloc(size * 10 * sizeof(int)); // bucket for radix sort
    int bucket_count[10] = {0}; // count for digit of each bucket
    for (int i = 0; i < number_of_passes; i++){
        int j,k;
        for (j = 0; j < size; j++){
            int digit_current_pass = (int)(array[j] / pow(10,i)) % 10 ;
            radix_bucket[digit_current_pass * size + bucket_count[digit_current_pass]] = array[j];
            bucket_count[digit_current_pass]++;
        }
        j=0; k=0;
        while (j < size && k < 10){
            int t = bucket_count[k];
            while(bucket_count[k]){
                array[j] = radix_bucket[t - bucket_count[k] + size * k];
                bucket_count[k] = bucket_count[k]-1;
                j++;
            }
            k++;
        }
    }

    free(radix_bucket);
}

int main(int argc, char* argv[]){
    int size, min_rand, max_rand;
    
    size = argc >= 2 ? atoi(argv[1]) : 1000000;
    min_rand = argc >= 3 ? atoi(argv[2]) : 1;
    max_rand = argc >= 4 ? atoi(argv[3]) : 100000;

    int *array = array_random_integers(size, min_rand, max_rand);

    print_array(array, size);
    double time_taken = sort_and_measure_time(array, size, radix_sort);
    print_array(array, size);

    printf("Time taken to sort : %lf \n",time_taken);
    cleanup_array(array);
    return 0;
}
