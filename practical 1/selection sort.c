#include <stdio.h>
int main() {
    int arr[] = {50, 10, 40, 20, 30};

    for (int i = 0; i < 4; i++) {
        int min = i;
        for (int j = i + 1; j < 5; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("ascending order: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
