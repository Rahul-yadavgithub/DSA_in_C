#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    ptr = (int*)calloc(5, sizeof(int));  // Allocating memory for 5 integers and initializing to 0

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr[i]);  // All values will be 0
    }

    free(ptr);  // Freeing the allocated memory
    return 0;
}
