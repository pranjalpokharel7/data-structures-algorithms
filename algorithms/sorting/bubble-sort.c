#include <stdio.h>
#include <stdlib.h>
#include "sorting_header.h"

void bubble_sort(int* array, int size){
   for (int i = 0; i < size; i++){
       for (int j = 0; j < size; j++){
           if (array[j] > array[j+1]){
               swap(&array[j], &array[j+1]);
           }
       }
   } 
}

int main(int argc, char* argv[]){
   int size, min_rand, max_rand;

   size = argc >= 2 ? atoi(argv[1]) : 10000;
   min_rand = argc >= 3 ? atoi(argv[2]) : 1;
   max_rand = argc >= 4 ? atoi(argv[3]) : 10000;

   int* array = array_random_integers(size, min_rand, max_rand);

   print_array(array, size);
   double time_taken = sort_and_measure_time(array, size, bubble_sort);
   print_array(array, size);

   printf("Time taken to sort the array is : %lf s\n",time_taken);
   cleanup_array(array); // run this function before the program ends to deallocate memory 
   return 0;
}
