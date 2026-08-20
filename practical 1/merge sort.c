#include <stdio.h>
void merge(int arr[], int start, int mid, int end) {
    int temp[100]; 
    int i = start;   
    int j = mid + 1; 
    int k = start;   

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int index = start; index <= end; index++) {
        arr[index] = temp[index];
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);    
    mergeSort(arr, mid + 1, end); 
    merge(arr, start, mid, end);  
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
  
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
