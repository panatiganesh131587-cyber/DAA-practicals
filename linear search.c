#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 30; 

    for (int i = 0; i < 5; i++) {
        if (arr[i] == n) {
            printf("Found at index %d\n", i);
            return 0; // Stop the program once found
        }
    }

    printf("Not found\n");
    return 0;
}
