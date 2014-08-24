#include<iostream.h>  
#define max 100
int main() 
{  
	int a[max]={0}; 
	int r[max][max]={0};
	int b[max][3]={0}; 
	int i,j,h,cmax; 
   int n; 
 
 cin>>n;   

for(i=1;i<=n;i++)  
    cin>>a[i];    
for(i=1;i<=n;i++)  
for(j=i;j<=n;j++)
 {       
 cin>>r[i][j];    }   
     
 for(i=n;i>0;i--) 
 {   cmax=0;h=0;   
   for(j=i;j<=n;j++)  
   {   if(r[i][j]==1 && b[j][1]>cmax) 
   {     h=j; 
         cmax=b[j][1];     }   
   b[i][1]=a[i]+cmax;  
   b[i][2]=h;    
   }   
   }   
   cmax=0; 
   h=0;  
   for(i=1;i<=n;i++)
   {    if(b[i][1]>cmax)   
   {    h=i;   
   cmax=b[i][1];   } 
   }   
   cout<<cmax<<endl; 
   if(h!=0)
	  cout<<h;
   while(b[h][2]!=0) 
   {   h=b[h][2];   cout<<"--->"<<h;  } 
   cout<<endl;
   system("pause"); 
return 0;
 }
