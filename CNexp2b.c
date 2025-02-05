#include<stdio.h>
#include<string.h>
int main(){
	int a[20],b[30],i,j,k,count,n;
	printf("Enter frame size in bits:");
	scanf("%d",&a[i]);
	i=0;
	count=1;
	j=0;
	while(i<n)
	{
		if(a[i]==1)
		{
			b[j]=a[i];
			for(k=i+1;a[k]==1&&k<n&&count<5;k++)
			{
				j++;
				b[j]=a[k];
				count++;
				if(count==5)
				{
					j++;
					b[j]=0;
				}
				i=k;
			}
		}
		else
		{
			b[j]=a[i];
		}i++;
		j++;
	}
	printf("After bit stuffing: ");
	printf("01111110");
	for(i=0;i<j;i++)
	printf("%d",b[i]);
	printf("01111110");
	return 0;
	}
 
