#include <stdio.h>
int main() {
    int arr[] = {50, 10, 40, 20, 30};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
