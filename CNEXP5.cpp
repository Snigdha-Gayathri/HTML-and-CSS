#include<stdio.h>
#include<math.h>
#include<string.h>
main()
{
int i,j,k,m,n,cl;
char a[10],b[100],c[100];
//clrscr();
printf("\n ENTER POLYNOMIAL:");
scanf("%s",a);
printf("\n ENTER THE FRAME:");
scanf("%s",b);
m=strlen(a);
n=strlen(b);
for(i=0;i<m;i++) /* To eliminat first zeros in polynomial */
{
if(a[i]=='1')
{
m=m-i; 
break;
}
}
for(k=0;k<m;k++) /* To Adjust the polynomial */ a[k]=a[k+i];
cl=m+n-1;
for(i=0;i<n;i++) /* To copy the original frame to c[]*/
c[i]=b[i];
for(i=n;i<cl;i++) /* To add n-1 zeros at the end of frame */
c[i]='0';
c[i]='\0'; /*To make it as a string */
for(i=0;i<n;i++) /* To set polynomial remainder at end of c[]*/
if(c[i]=='1')
{
for(j=i,k=0;k<m;k++,j++)
if(a[k]==c[j])
c[j]='0';
else c[j]='1';
}
for(i=0;i<n;i++) /* To copy original data in c[]*/ c[i]=b[i];
printf("\n THE MESSAGE IS: %s",c);

}

