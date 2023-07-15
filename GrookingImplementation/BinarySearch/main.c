#include <stdio.h>

int binary_search(int arr[], int l, int r, int x);


int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int result = binary_search(arr, 0, 10, 80);
    if (result == -1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d", result);
    return 0;
}
int binary_search(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            return binary_search(arr, mid + 1, r, x);
        else
            return binary_search(arr, l, mid - 1, x);
    }
    return -1;
}
