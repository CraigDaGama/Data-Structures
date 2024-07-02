#include<stdio.h>
int main()
{
    int n,i,item,index,arr[50];
    printf("enter no of elements\n");   /*accept number of elements*/
    scanf("%d",&n);
    printf("enter elements\n"); /*accept elements*/
    for(i=0; i<n; i++)
        scanf("%d",& arr[i]);
    printf("enter element to be searched\n");   /*accept key element*/
    scanf("%d",&item);
    index=Binarysearch(arr,n,item);
    if(index== -1) printf("element not found\n");
    else printf("element found at index %d\n",index);
}
int Binarysearch(int arr[],int n,int item)      /*Binary search function*/
{
    int low=0,up=n-1,mid;
    while(low<=up)
    {
        mid=(low+up)/2;
        if (item>arr[mid])
            low=mid+1;
        else if(item<arr[mid])
            up=mid-1;
        else return mid;
    }
    return -1;
}
