// Merge sort
// 22co10 Craig Da Gama
#include<stdio.h>
int mergesort(int a[], int low, int high)
{
int temp[50];
int mid=(low+high)/2;

if(low<high)
    {
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);

    merge(a,temp,low,mid,mid+1,high);
    copy(a,temp,low,high);
    }
return 0;
}

int merge(int a[], int temp[], int low1, int high1, int low2, int high2)
{
    int i=low1, j=low2, k=low1;
    while((i<=high1) && (j<=high2))
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }

    while(i<=high1)
        { temp[k++]=a[i++]; }
    while(j<=high2)
    { temp[k++]=a[j++]; }

}

int copy(int a[], int temp[], int low, int high)
{
    int i;
    for(i=low;i<=high;i++)
    a[i]=temp[i];
    return 0;
}

int display(int a[], int low, int high)
{
    int i;
    for(i=low;i<=high;i++)
    printf("%d ",a[i]);
    return 0;
}

int main()
{
    int a[50], n, low, high, i;
    printf("Enter the total number of elements :");
    scanf("%d",&n);

    printf("Enter the elements : ");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    low=0;
    high=n-1;

    mergesort(a, low, high);
    display(a, low, high);
    return 0;
}
