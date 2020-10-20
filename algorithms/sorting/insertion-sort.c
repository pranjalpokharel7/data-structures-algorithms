#include <stdio.h> 

void print_array(int* arr, int n){
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr+i));
    printf("\n"); 
}

void insertion_sort(int* arr, int n){
    int j, key;
    for (int i = 1  ; i < n; i++){
        j = i - 1;
        key = *(arr + i);
        while (j >=0 && *(arr + j) > key){
            *(arr+j+1) = *(arr+j); 
            j--;
        }
        *(arr+j+1) = key;
    } 
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr,n);
    print_array(arr,n);
}
