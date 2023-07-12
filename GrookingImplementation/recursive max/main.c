#include <stdio.h>

int Max(int arr[], int size);

int main()
{
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    int res=Max(arr,size);
    printf("The max element = %d",res);
    return 0;
}
int Max(int arr[], int size)
{
    if (size == 1)
        return arr[0];
    else {
        int max = Max(arr+1, size-1);
        if (arr[0] > max)
            return arr[0];
         else
            return max;
    }
}
