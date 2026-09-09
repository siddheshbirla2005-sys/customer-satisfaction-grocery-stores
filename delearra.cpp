#include<iostream>

int main() {
    int array[10] = {1, 3, 5, 7, 9};
    int length = 5;
    
    // Delete elements greater than 5 
    for (int i = 0; i < length; ++i) {
        if (array[i] > 5) {
            // Shift elements to fill the gap created by the deleted element
            for (int j = i; j < length - 1; ++j){
            array[j] = array[j + 1];
        }
        // Decrement the length of the array 
        --length;
        // Adjust the index to recheck the current position in the next iteration
        --i;
        }
    }
    
    // Print the updated array 
    for (int i = 0; i < length; ++i){
        std::cout << array[i] <<" ";
    }
    
    return 0;
}
