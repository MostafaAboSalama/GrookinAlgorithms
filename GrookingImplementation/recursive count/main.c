#include <stdio.h>
#include <stdlib.h>

int count(int arr[], int index);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,7,8};
    int len = count(arr, 0);
    printf("Number of elements: %d\n", len);
    return 0;
}

int count(int arr[], int index)
{
    if (arr[index] == '\0') {
        return index-1;
    } else {
        return count(arr, index + 1);
    }
}
