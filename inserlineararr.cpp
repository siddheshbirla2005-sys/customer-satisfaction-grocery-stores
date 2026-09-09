# include<iostream>

int main(){
    int array[10] = {1, 3, 5, 7, 9};
    int length = 5;
    
    // Insert an element (e.g., 6) at the position where the value is greater than 5 
    for(int i = 0; i < length; ++i){
        if (array[i]  > 5) {
           // Shift element to make room for the new element
           for (int j = length; j > i; --j){
           array [j] = array[j - 1];
           }
           // Insert the new element 
           array[i] = 6;
           // Increment the length of the array 
           ++length;
           // Break to avoid inserting multiple times 
           break;
        }
}

// Print the updated array 
for (int i = 0;  i < length; ++i){
    std::cout << array[i] << " ";
}


return 0;
}
