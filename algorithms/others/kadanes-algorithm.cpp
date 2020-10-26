#include <iostream>

int max_value (int a, int b){
    return a > b ? a : b;
}

int calculate_max_subarray(int* array, int size) {
    int current_max, global_max;
    current_max = global_max = array[0];

    for (int i = 0; i < size; i++){
        current_max = max_value(array[i], current_max + array[i]); 
        global_max = max_value(global_max, current_max);
    }
    return global_max;
}

int main(){
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15,  
                   -4, 7};
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "The maximum subarray value is : " 
        << calculate_max_subarray(array, size) << "\n";
}
