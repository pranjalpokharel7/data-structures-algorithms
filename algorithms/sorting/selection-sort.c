#include <stdio.h>
#include "sorting_header.h"

void swap_values(int* x, int* y){
   int t = *x; 
   *x = *y;
   *y = t;
}

void selection_sort(int* array, int size){
   int i, j;  
   for (i=0; i<size; i++){
      for (j=i+1; j<size-1; j++)
         if (array[j] < array[i])
            swap_values((array+i), (array+j));
   }
   print_array(array, size); 
}

int main(){
   int size = 100000;
   int min_rand = 1, max_rand = 10000;
   int* array = array_random_integers(size, min_rand, max_rand);

   printf("Unsorted Array: \n");
   print_array(array, size);
   double time_taken = sort_and_measure_time(array, size, selection_sort);
   printf("Sorted Array: \n");
   print_array(array, size);
   printf("Time taken to sort the array is : %lf",time_taken);

   cleanup_array(array); // run this function before the program ends to deallocate memory 

   return 0;
}
