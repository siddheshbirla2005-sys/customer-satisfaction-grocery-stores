#include<iostream>

int main(){
    // Initializing an Array 
    int array[] = {10, 23, 5, 17, 8};
    int length = sizeof(array) / sizeof(array[0]);
    
    // Forward transversal 
    std::cout <<"Forward Tranversal: ";
    for(int i = 0; i < length; ++i) {
        // Accessing and printing each element in the forward direction
        std::cout << array[1] << " " ;
}
std::cout << std::endl;

// Backward transversal
std::cout << "Backward Transversl: ";
for (int i = length - 1; i >=0; --i) {
    // Accessing and printing each element in the backward direction
    std::cout << array[i] << " ";
}
std::cout << std::endl;

return 0;
}
