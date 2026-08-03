#include <stdio.h>
int main() {
    int a[5] = {10, 20, 30, 40, 50};
    int low = 0, high = 4, mid, key = 30;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            printf("Element found");
            return 0;
        }
        else if (key > a[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Element not found");
    return 0;
}
