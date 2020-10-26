#include <stdio.h>
#include "searching-header.h"

int binary_search(int *array, int item_to_search, int l, int n){
  if (l > n) 
    return -1;

  int m = l + (n-l)/2;
  if (array[m] == item_to_search)
    return m;
  
  if (array[m] < item_to_search)
    return binary_search(array, item_to_search, m, n);

  return binary_search(array, item_to_search, l, m); 

}

int binary_search_wrapper(int* array, int size, int item_to_search){
  return binary_search(array, item_to_search, 0, size-1);
}

int main(){
  int array[] = {1,2,3,5,6,10,12};
  int size = sizeof(array)/sizeof(array[0]);
  int item_to_search = 10;

  double time_taken = search_and_measure_time(array, size, 
      item_to_search, binary_search_wrapper);
  printf("Time taken to search for the item : %lf s\n",time_taken);
  return 0;
}
