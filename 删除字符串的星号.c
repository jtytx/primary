#include<stdio.h>
main()
{ void fun(char *s,char *p);
  char s[20],*p;
  scanf("%s",s);
  p=s;
  while(*p) p++;
  p--;
  while(*p=='*')
  p--;
  fun(s,p);
  printf("%s",s);
  system("pause");}
  
void fun(char *s,char *p) 
{int k=0;
 char *q;
 q=s;
for(;s<=p;s++)
if(*s!='*')
q[k++]=*s;
while(*s)
{q[k++]=*s;s++;} 
q[k]='\0';}
