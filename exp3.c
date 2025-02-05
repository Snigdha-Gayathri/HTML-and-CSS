#include<stdio.h>
int partition(int *arr,int L,int n)
{
int i,j,p,temp;
p=n;
for(i=L,j=L;j<p;j++)
{
if(arr[j]<arr[p])
{
temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;
i++;
}
}
temp=arr[i];
arr[i]=arr[p];
arr[p]=temp;
return i;
}
void quick_sort(int *arr,int L,int n)
{
int p,i;

if(L<n)
{
p=partition(arr,L,n);
quick_sort(arr,L,p-1);
quick_sort(arr,p+1,n);
}
}
void main()
{
int arr[100],i,n;
printf("Enter the size of the array:");
scanf("%d",&n);
printf("Enter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
quick_sort(arr,0,n-1);
printf("Sorted Array:");
for(i=0;i<n;i++)
{
printf("%d",&arr[i]);
}
}
