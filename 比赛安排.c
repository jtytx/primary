#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef unsigned int  uint16;
typedef unsigned long uint32;

uint32 power(uint32,uint32);


int main(void)
{
 char now[16] = {0};   
 char befor[16][16] = {0}; 
 uint16 i = 0,j = 0,k = 0,a = 0,n = 0; 
 uint16 amount = 0;   

 scanf("%d",&n); 
 
 amount = power(2,n); 
 for(i = 0; i < 16; i++)
 {
  befor[i][i] = 1;
 }

 for(i = 0; i < amount - 1; i++)
 {
  printf("<%d>",i+1);
  
  memset(now,0,sizeof(now));
 
  for(j = 0; j < amount / 2; j++)
  {
    
   for(k = 0; k < amount; k++)
   {
    
    if(now[k] == 0)
    {
     break; 
    }
   }
   
   for(a = 0; a < amount; a++)
   {
   
    if(befor[k][a] == 0 && now[a] == 0)
    {
     break; 
    }
   }
   
   now[k] = 1;
   now[a] = 1;
   befor[k][a] = 1;
   befor[a][k] = 1; 
   printf("%d-%d ",k+1,a+1); 
  }
  printf("\n");
 }
 return 0;
}
uint32 power(uint32 x, uint32 y)
{ uint32 sum = 1;
  int i;
 if(y <= 0) exit(0);
 

 for(i = 0; i < y; i++)
 {
  sum *= x;
 }
 
 return sum;
}