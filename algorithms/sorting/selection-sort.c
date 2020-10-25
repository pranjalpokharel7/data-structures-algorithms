#include <stdio.h>
#include "sorting_header.h"

void selection_sort(int* array, int size){
   int i, j;  
   for (i=0; i<size; i++){
      for (j=i+1; j<size-1; j++)
         if (array[j] < array[i])
            swap(&array[i], &array[j]);
   }
   print_array(array, size); 
}

int main(int argc, char* argv[]){
   int size, min_rand, max_rand;
    
   size = argc >= 2 ? atoi(argv[1]) : 1000000;
   min_rand = argc >= 3 ? atoi(argv[2]) : 1;
   max_rand = argc >= 4 ? atoi(argv[3]) : 100000;

   int* array = array_random_integers(size, min_rand, max_rand);

   print_array(array, size);
   double time_taken = sort_and_measure_time(array, size, selection_sort);
   print_array(array, size);

   printf("Time taken to sort the array is : %lf",time_taken);
   cleanup_array(array); // run this function before the program ends to deallocate memory 
   return 0;
}
