/*program to perform linear search*/
/*22co10 Craig Da Gama*/
#include<stdio.h>
int main()
{
    int n,i,arr[50],item,index;
    printf("enter number of elements\n");       /*accepting number of elements*/
    scanf("%d",&n);
    printf("enter the elements\n");      /*accepting the elements*/
    for(i=0;i<n;i++)
    scanf("%d",& arr[i]);
    printf("enter element to be searched\n");        /*accepting element to be searched*/
    scanf("%d",& item);
    index=linearsearch(arr,n,item);
    if (index==-1)
    printf("element %d not found\n",item);
    else
    printf("element %d found at index %d\n",item,index);
}
int linearsearch(int arr[],int n,int item)       /*linearsearch function*/
{
    int i=0;
    while(i<n && arr[i]!=item)
    i++;
    if(i<n) return i;
    else return -1;
}
