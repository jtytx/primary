#include<stdio.h>
int main()
{int a1,a2,a3,a4,a5,a6,i,j,k,l,m,n,w;
int arry[1000]={0};
 long int s;
scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
for(i=0;i<=a1;i++)
for(j=0;j<=a2;j++)
for(k=0;k<=a3;k++)
for(l=0;l<=a4;l++)
for(m=0;m<=a5;m++)
for(n=0;n<=a6;n++)
{s=i+j*2+k*3+l*5+m*10+n*20;
arry[s]=1;}
s=0;
for(w=1;w<1000;w++)
s+=arry[w];
printf("Total=%ld\n",s);
return 0;
}
