#include<stdio.h>
#include<stdlib.h>
void countingsort(int a[], int b[], int n, int k)
{

    int pos[k+1];
    memset(pos, 0, (k+1)*sizeof(pos[0]));

    int i, j;
    for(i = 0; i < n; i++)
    {
        pos[a[i]]++;
    }
    for(i =1; i<k + 1; i++)
    {
        pos[i] = pos[i-1] + pos[i];
    }
    for(j = n -1; j >=0; j--)
    {
        b[pos[a[j]] - 1] = a[j];
        pos[a[j]]--;

    }

}

int main()
{
    int arr[] = {3, 2, 9, 5, 3, 0, 1, 3, 6};
    int size = 0; int i;
    size = sizeof(arr)/sizeof(int);
    int sortedarr[size];
    countingsort(arr, sortedarr, size, 9);
    for(i =0; i< size; i++)
        printf("%d ", sortedarr[i]);
}
