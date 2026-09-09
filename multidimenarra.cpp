#include<iostream>

int main() {
    // Declare a 2x3 matrix
    int matrix[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    
    
    // Access and print elements
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "matrix[" << i << "][" << j << "] = " << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
