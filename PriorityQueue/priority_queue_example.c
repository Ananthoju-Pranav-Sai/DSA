#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void max_heapify(int arr[],int priority[],int time[],int n,int i)
{
    int curr=i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n)
    {
        if(priority[arr[l]-1]<priority[arr[curr]-1])
            curr=l;
        else if(priority[arr[l]-1]==priority[arr[curr]-1])
        {
            if(time[arr[l]-1]>time[arr[curr]-1])
            {
                curr=l;
            }
        }
    }
    if(r<n)
    {
        if(priority[arr[r]-1]<priority[arr[curr]-1])
            curr=r;
        else if(priority[arr[r]-1]==priority[arr[curr]-1])
        {
            if(time[arr[r]-1]>time[arr[curr]-1])
            {
                curr=r;
            }
        }
    }
    if(curr!=i)
    {
        swap(arr+i,arr+curr);
        max_heapify(arr,priority,time,n,curr);
    }
}
void build_max_heap(int arr[],int priority[],int time[],int n)
{
    int ind = (n/2)-1;
    for(int i=ind;i>=0;i--)
    {
        max_heapify(arr,priority,time,n,i);
    }
}
int extract_max(int arr[],int priority[],int time[],int n)
{
    int res = arr[0];
    swap(arr,arr+n-1);
    max_heapify(arr,priority,time,n-1,0);
    return res;

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int priority[]={2,3,1,2,1,2,2,1,3,2,1,2};
    int time[]={30,20,40,10,25,20,35,30,30,20,20,20};
    int start_time[]={0,0,0,0,0,0,25,60,70,150,190,210};
    int n=6;
    build_max_heap(arr,priority,time,n);
    int l=1;
    for(int i=0;i<6;i++)
    {
        int j = extract_max(arr,priority,time,n-i);
        printf("Job %d Time : %d-%d",j,l,l+time[j-1]-1);
        l=l+time[j-1];
        printf("\n");
    }
}