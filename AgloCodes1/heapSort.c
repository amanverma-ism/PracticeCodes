#include<stdio.h>
#include<stdlib.h>

void max_heapify(int arr[], int currPos, int heapsize)
{
    int left = currPos<<1;
    int right = left + 1;
    int largestPos;
    if(left< heapsize && arr[currPos] < arr[left])
        largestPos = left;
    else
        largestPos = currPos;
    if(right < heapsize && arr[largestPos] < arr[right])
        largestPos = right;
    if(largestPos != currPos)
    {
        int temp = arr[currPos];
        arr[currPos] = arr[largestPos];
        arr[largestPos] = temp;
        max_heapify(arr, largestPos, heapsize);
    }
}

void build_max_heap(int arr[], int len, int *heapsize)
{
    (*heapsize) = len;
    int i;
    for(i = len/2 - 1; i>=0; i--)
    {
        max_heapify(arr, i, (*heapsize));
    }
}

void heapsort(int arr[], int len)
{
    if(len <=1)
        return;
    int heapsize;
    build_max_heap(arr, len, &heapsize);
    int i;
    for(i = len -1; i >=1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapsize = heapsize - 1;
        max_heapify(arr, 0, heapsize);
    }
}

int main()
{
    int arr[] = {564,354,54,987,351,984,37,8375,9,874,35,6,8,24};
    int size = 0;
    size = sizeof(arr)/sizeof(int);
    heapsort(arr, size);
    int i;
    for(i =0; i< size; i++)
        printf("%d ", arr[i]);
    return 0;
}
