// Header file to generate set of array for sorting

void swap(int* a, int* b);
void print_array(int* array, int size);
int* array_reverse_sorted_integers(int size);
int* array_random_integers(int size, int min, int max);
double sort_and_measure_time(int* array, int size, void (*fp)(int*, int));
void cleanup_array(int* array);
