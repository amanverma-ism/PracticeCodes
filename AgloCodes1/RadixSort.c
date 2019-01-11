#include<stdio.h>
#include<stdlib.h>
void countingsort(int a[], int n, int k)
{
    int b[n];
    int pos[10];
    memset(pos, 0, (10)*sizeof(pos[0]));

    int i, j;
    for(i = 0; i < n; i++)
    {
        pos[(a[i]/k)%10]++;
    }
    for(i =1; i<10; i++)
    {
        pos[i] = pos[i-1] + pos[i];
    }
    for(j = n -1; j >=0; j--)
    {
        b[pos[(a[j]/k)%10] - 1] = a[j];
        pos[(a[j]/k)%10]--;
    }
    for(i =0; i<n; i++)
        a[i]=b[i];
}

int getMax(int arr[], int n)
{
    int i, max = arr[0];
    for(i = 0; i<n ;i++)
        if(arr[i] > max)
            max = arr[i];
    return max;
}

void radixsort(int arr[], int n)
{
    int maxval = getMax(arr, n);
    int i;
    for(i = 1; maxval/i > 0; i*=10)
        countingsort(arr, n, i);
}

int main()
{
    int arr[] = {3, 354, 12, 86, 2, 9, 904, 234,98,45, 5, 3, 435,86,32, 0, 1, 76,49,77, 3, 6};
    int size = 0; int i;
    size = sizeof(arr)/sizeof(int);
    radixsort(arr, size);
    for(i =0; i< size; i++)
        printf("%d ", arr[i]);
}
