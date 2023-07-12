#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x, int *y);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int size;
    printf("Enter the size : ");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements : \n");
    for (int i = 0; i < size; i++)
    {
        printf("The element [%d] = ",i);
        scanf("%d",&arr[i]);
    }

    quicksort(arr, 0, size - 1);
    printf("____________________/n");
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
      {
          int pivot_index=partition(arr,low,high);
          quicksort(arr,low,pivot_index-1);
          quicksort(arr,pivot_index+1,high);
      }
}

int partition(int arr[],int low,int high)
{
    int i=low;
    int j;
    int pivot_index = low + (rand() % (high - low));
    if(pivot_index != high)
        swap(&arr[pivot_index],&arr[high]);
    for(j=low;j<high;j++)
    {
        if(arr[j]<=arr[high])
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[high],&arr[i]);
    return i;

}
