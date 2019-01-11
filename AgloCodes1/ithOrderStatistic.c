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

int orderStatistic(int arr[], int p, int r, int k)
{
    if(p == r)
    {
        return arr[p];
    }
    int q = partition(arr, p, r);
    printf("q= %d\n", q);
    if(q == k - 1)
    {
        return arr[q];
    }
    if(q > k - 1)
        return orderStatistic(arr, p, q-1, k);
    else
        return orderStatistic(arr, q+1, r, k);
}

int main()
{
    int arr[] = {564,354,54,987,351,984,37,875,9,874,35,6,8,24};
    int size = 0;
    size = sizeof(arr)/sizeof(int);
    printf("%d ", orderStatistic(arr, 0, size - 1, 6));
}
