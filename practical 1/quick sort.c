#include <stdio.h>
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left, j = right;

    while (i < j) {
        while (arr[i] <= pivot && i < right) i++;
        while (arr[j] > pivot) j--;

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[left] = arr[j];
    arr[j] = pivot;
    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
