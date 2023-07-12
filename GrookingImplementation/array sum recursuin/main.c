#include <stdio.h>
#include <stdlib.h>

int Sum(int arr[], int size);

int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++)
    {
        printf("Enter the [%d] element : ",i);
        scanf("%d",&arr[i]);
    }
    int res = Sum(arr, size);
    printf("%d",res);
    return 0;
}

int Sum(int arr[], int size)
{
    if (size == 0)
        return 0;

    int sum = arr[size-1] + Sum(arr, size-1);
    return sum;
}
