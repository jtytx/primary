#include<stdio.h>
#include<string.h>
int main()
{int n,i,j,k,l,sum,min,d1,max1;
int d[1000]={0};
char s[100][1000]={'\0'};
char n1,x1,p;
scanf("%d",&n);
for( i=0;i<n;i++)
scanf("%s",s[i]);
for(i=0;i<n;i++) 
{k=strlen(s[i]); 
 max1=0;
 for(j=0;j<k;j++)
   for(l=0;l<k;l++)
   {d1=s[i][j]-s[i][l];
   if(d1<0) d1=-d1;
   if(d1>13) d1=26-d1;
   if(d1>max1&&j!=l&&d1!=0) 
      {max1=d1;
       n1=s[i][j];
       x1=s[i][l];}
   }
if(n1>x1) {d1=n1;n1=x1;x1=d1;}
if(x1-n1<13)
  {for(p=n1;p<=x1;p++)  
    {sum=0;   
     for(j=0;j<k;j++)   
      {if((p-s[i][j])<0) d[j]=s[i][j]-p;
       else d[j]=p-s[i][j]; 
       if(d[j]>13) d[j]=26-d[j]; 
        sum+=d[j]; 
       if(p==n1) min=sum;
       }
     if(sum<min) min=sum;   
     }
   }
else
   {p=x1;
   while(p!=(n1+1))
     {if(p>'z') p-=26;
      sum=0;
      for(j=0;j<k;j++)   
       {if((p-s[i][j])<0) d[j]=s[i][j]-p;
        else d[j]=p-s[i][j]; 
        if(d[j]>13) d[j]=26-d[j]; 
        sum+=d[j]; 
        if(p==x1) min=sum;
        }
      if(sum<min) min=sum;
      p++;    
      }
   }
if(max1==0) printf("0\n");    
else printf("%d\n",min);
}
 system("pause");
return 0;
}
 

 
 
 




