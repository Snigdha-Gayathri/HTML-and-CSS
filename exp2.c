#include<stdio.h>
void merge(int *arr,int si,int m,int ei)
{
int i=si;
int j=m+1;
int k=0;
int temp[ei-si+1];
while(i<=m&&j<=ei)
{
if(arr[i]<=arr[j])
{
temp[k++]=arr[i++];
}
else
{
temp[k++]=arr[j++];
}
}

while(i<=m)
{
temp[k++]=arr[i++];
}
while(j<=ei)
{
temp[k++]=arr[j++];
}
int s=0;
for(i=si;i<=ei;i++)
{
arr[i]=temp[s++];
}
}
void divide(int *arr,int beg,int end)
{
if(beg<end)
{
int mid=(beg+end)/2;
divide(arr, beg,mid);
divide(arr,mid+1,end);
merge(arr,beg,mid,end);
}
}
void main()
{
int n,i,beg,end;
printf("Enter the size of the array:");
scanf("%d",&n);
printf("Enter the elements in the array:");
int arr[n];
for(i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("array before mergesort \n");
for(i=0;i<n;i++)

{
printf("%d",arr[i]);
}
beg=0;
end=n-1;
divide(arr,beg,end);
printf("\n");
printf("array after mergesort \n");
for(i=0;i<n;i++)
{
printf("%d",arr[i]);
}
}
