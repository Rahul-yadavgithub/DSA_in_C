// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int *ptr;
//     ptr = (int*)malloc(5 * sizeof(int));  // Allocating memory for 5 integers

//     if (ptr == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }

//     for (int i = 0; i < 4; i++) {
//         ptr[i] = i + 1;
//     }

//     for (int i = 0; i < 5; i++) {
//         printf("%d ", ptr[i]);
//     }

//     free(ptr);  // Freeing the allocated memory
//     return 0;
// }


#include <stdio.h>

int* function() {
    int x = 10;          // Local variable 'x'
    return &x;           // Returning address of 'x' (dangerous)
}

int main() {
    int *ptr = function();  // 'ptr' is now a dangling pointer
    // printf("Before any new function call: %d\n", *ptr);  // Undefined behavior

    // Simulating more stack usage
    int y = 20;            // New local variable in 'main'
    printf("Value of y: %d\n", y);
    // printf("After new variable creation: %d\n", *ptr);  // Undefined behavior, may have changed
    
    return 0;
}







