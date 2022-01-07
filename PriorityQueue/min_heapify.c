#include <stdio.h>
#include <stdlib.h>


void min_heapify(int arr[],int n,int i)
{
    int curr=i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]<arr[curr])
    {
        curr=l;
    }
    if(r<n && arr[r]<arr[curr])
    {
        curr=r;
    }
    if(curr!=i)
    {
        int temp = arr[i];
        arr[i] = arr[curr];
        arr[curr]=temp;
        min_heapify(arr,n,curr);
    }
}
void build_min_heap(int arr[],int n)
{
    int ind = (n/2)-1;
    for(int i=ind;i>=0;i--)
    {
        min_heapify(arr,n,i);
    }
}
int main()
{
    int arr[] = {1,3,5,4,6,13,10,9,8,15,17};
    int n=11;
    build_min_heap(arr,n);
    for(int i=0;i<11;i++)
    {
        printf("%d ",arr[i]);
    }
}