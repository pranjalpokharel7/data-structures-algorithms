#include <stdio.h>
#include <stdbool.h>
#include "searching-header.h"

int linear_search(int* array, int size, int item_to_search){
  int item_position = -1;
  for (int i = 0; i < size; i++){
    if (array[i] == item_to_search){
      item_position = i;
      break;
    }
  }

  return item_position;
}

int main(int argc, char** argv){
  int size, min_rand, max_rand, item_to_search;


  item_to_search = argc >= 2 ? atoi(argv[3]) : 24;
  size = argc >= 2 ? atoi(argv[1]) : 1000;
  min_rand = argc >= 3 ? atoi(argv[2]) : 1;
  max_rand = argc >= 4 ? atoi(argv[3]) : 1000;

  int *array = get_array_random_integers(size, min_rand, max_rand);
  print_array(array, size);
  double time_taken = search_and_measure_time(array, size, 
      item_to_search, linear_search);

  printf("Time taken to search for the item : %lf s \n", time_taken);
  cleanup_array(array);
}
