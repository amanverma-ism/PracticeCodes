#include<stdio.h>

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    int j;
    for(j = p; j<r; j++)
    {
        if(arr[j] < x)
        {
            i = i + 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i+1;
}

void quicksort(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int main()
{
    int arr[] = {564,354,54,987,351,984,37,8375,9,874,35,6,8,24};
    int size = 0;
    size = sizeof(arr)/sizeof(int);
    quicksort(arr, 0, size - 1);
    int i;
    for(i =0; i< size; i++)
        printf("%d ", arr[i]);
}
