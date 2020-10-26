#include <iostream>
#include <climits>

struct MaxSubArray {
    int max_left_index;
    int max_right_index;
    int max_sub_array_sum;
};

MaxSubArray find_max_crossing_subarray(int* array, int low, 
        int mid, int high){
    MaxSubArray max_subarray;
    int left_sum, right_sum;
    left_sum = right_sum = INT_MIN;

    int sum = 0, i;
    for (i = mid; i >= low; i--){
        sum += array[i];
        if (sum > left_sum){
            left_sum = sum;
            max_subarray.max_left_index = i;
        }
    }

    sum = 0;
    for (i = mid + 1; i <= high; i++){
        sum += array[i];
        if (sum > right_sum){
            right_sum = sum;
            max_subarray.max_right_index = i;
        }
    }

    max_subarray.max_sub_array_sum = left_sum + right_sum;
    return max_subarray;
}

MaxSubArray find_max_subarray(int* array, int low, int high){
    MaxSubArray max_subarray;
    MaxSubArray left_max, cross_max, right_max;
    if (high == low){
        max_subarray.max_left_index = low;
        max_subarray.max_right_index = high;
        max_subarray.max_sub_array_sum = array[low];
        return max_subarray;
    }

    int mid = low + (high - low)/2;
    left_max = find_max_subarray(array, low, mid);
    right_max = find_max_subarray(array, mid+1, high);
    cross_max = find_max_crossing_subarray(array, low, mid, high);

    if (left_max.max_sub_array_sum >= right_max.max_sub_array_sum &&
            left_max.max_sub_array_sum >= cross_max.max_sub_array_sum)
        return left_max;

    if (right_max.max_sub_array_sum >= left_max.max_sub_array_sum &&
            right_max.max_sub_array_sum >= cross_max.max_sub_array_sum)
        return right_max;

    return cross_max;
}

void print_array(int* array, int size){
    std::cout << "The array in full is : \n[ ";
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "] \n";
}

int main(){
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, 
        -4, 7};
    int size = sizeof(array)/sizeof(array[0]);
    MaxSubArray max_subarray = find_max_subarray(array, 0, size-1);

    std::cout << "The maximum subarray is : \n[ ";
    for (int i = max_subarray.max_left_index; 
            i <= max_subarray.max_right_index; i++)
        std::cout << array[i] << " ";
    std::cout << "]";
}
