#include<stdio.h>
int main()
{ int combi(int,int);
  int gcd(int,int);
  int com,n,m;
  int  a[5000]={0},b[5000][2]={0},i,t;
  int *p,*q;
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
  for(i=1;i<=m;i++)
	  scanf("%d%d",&b[i][0],&b[i][1]);
for(i=1;i<=m;i++)
{t=0;
com=combi(b[i][0],b[i][1]);
for(p=a+b[i][0];p<=a+b[i][1];p++)
for(q=a+b[i][0];q<=a+b[i][1];q++)
if(*p==*q&&p!=q) t++;
t=t/2;
if(t==0) printf("0/1\n");
else printf("%d/%d\n",t/gcd(t,com),com/gcd(t,com));
}
return 0;
}
int combi(int x,int y)
{ int fac(int);
  int z;
z=fac(y-x+1)/(2*fac(y-x-1));
return(z);
}
int fac(int k)
{ int t=1,i;
for(i=2;i<=k;i++)
t*=i;
return(t);
}
int gcd(int x,int y)
{ int r=1,t;
if(x<y) {t=x;x=y;y=t;}
while(r!=0)
{r=x%y;
x=y;
y=r;}
return(x);
}



