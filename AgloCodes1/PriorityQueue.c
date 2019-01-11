#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int heap_maximum(int arr[])
{
    return arr[0];
}

void max_heapify(int arr[], int i, int heapsize)
{
    int l = (i+1)*2 - 1;
    int r = l+1;
    int largest;
    //printf("l = %d, r = %d, arr[i] = %d\n", l, r, arr[i]);
    if(l < heapsize && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if(r < heapsize && arr[r] > arr[largest])
        largest = r;
    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr, largest, heapsize);
    }
}

int heap_extract_max(int arr[], int *heapsize)
{
    if((*heapsize) < 1)
    {
        printf("heap underflow\n");
        return;
    }
    int max = arr[0];
    arr[0] = arr[(*heapsize) - 1];
    (*heapsize) = (*heapsize) - 1;
    max_heapify(arr, 0, (*heapsize));
    return max;
}

void heap_increase_key(int arr[], int i, int key)
{
    if(arr[i] > key)
    {
        printf("error!!! new key is smaller than current key\n");
        return;
    }
    arr[i] = key;
    while(i > 0 && arr[(i/2)] < arr[i])
    {
        int temp = arr[i];
        arr[i] = arr[i/2];
        arr[i/2] = temp;
        i = i/2;
    }
}

void build_max_heap(int arr[], int len, int *heapsize)
{
    (*heapsize) = len;
    int i;
    for(i = len/2; i >= 0; i--)
    {
        max_heapify(arr, i, (*heapsize));
    }
}

void heapsort(int arr[], int len)
{
    int heapsize;
    build_max_heap(arr, len, &heapsize);
    int i;
    for(i = len - 1; i>=1; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapsize = heapsize - 1;
        max_heapify(arr, 0, heapsize);
    }
}

void max_heap_insert(int arr[], int key, int *heapsize)
{
    (*heapsize) = (*heapsize) + 1;
    arr[(*heapsize) -1] = INT_MIN;
    heap_increase_key(arr, (*heapsize) - 1, key);
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
    printf("\n");
    int heapsize = 0;
    build_max_heap(arr, size, &heapsize);
    for(i =0; i< size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("maxval = %d\n", heap_maximum(arr));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("maxval = %d\n", heap_maximum(arr));
    printf("increasing the key 3 to 10000\n");
    heap_increase_key(arr, 3, 10000);
    printf("maxval = %d\n", heap_maximum(arr));
    printf("inserting value 9000\n");
    max_heap_insert(arr, 9000, &heapsize);
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    printf("extract maxval = %d\n", heap_extract_max(arr, &heapsize));
    return 0;
}
