#include<stdio.h>
#include<string.h>
int main()
{int max4(int,int,int,int);
 char s[10][100]={'\0'};
 int N,i,j,k,a,g,c,t,max;
 scanf("%d",&N);
 for(i=0;i<N;i++)
 scanf("%s",s[i]);
k=strlen(s[0]);
for(j=0;j<k;j++)
{a=g=c=t=0;
 for(i=0;i<N;i++)
{if(s[i][j]=='A') a++;
 if(s[i][j]=='G') g++;
 if(s[i][j]=='C') c++;
 if(s[i][j]=='T') t++;}
 max=max4(a,g,c,t);
 if(max==a) printf("A");
 else if(max==c) printf("C");
      else if(max==g) printf("G");
           else printf("T");
}
system("pause");
return 0;
}
int max4(int a,int g,int c,int t)
{int max;
max=(a>g)?a:g;
max=(max>c)?max:c;
max=(max>t)?max:t;
return(max);
}
