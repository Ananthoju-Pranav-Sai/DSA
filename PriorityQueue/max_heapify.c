#include <stdio.h>
#include <stdlib.h>


void max_heapify(int arr[],int n,int i)
{
    int curr=i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[curr])
    {
        curr=l;
    }
    if(r<n && arr[r]>arr[curr])
    {
        curr=r;
    }
    if(curr!=i)
    {
        int temp = arr[i];
        arr[i] = arr[curr];
        arr[curr]=temp;
        max_heapify(arr,n,curr);
    }
}
void build_max_heap(int arr[],int n)
{
    int ind = (n/2)-1;
    for(int i=ind;i>=0;i--)
    {
        max_heapify(arr,n,i);
    }
}
int main()
{
    int arr[] = {1,3,5,4,6,13,10,9,8,15,17};
    int n=11;
    build_max_heap(arr,n);
    for(int i=0;i<11;i++)
    {
        printf("%d ",arr[i]);
    }
}