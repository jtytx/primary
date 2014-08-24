#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
//#include <windows.h>
 
using namespace std;
const int MAXN = 15;
 
int n, mine[MAXN];
bool relat[MAXN][MAXN];
bool mark[MAXN];
int sub, temp_road[MAXN];
int ans, final_road[MAXN], longOfRoad;
 
void input (void)
{
	cin >> n;
	
	for (int i=1; i<=n; i++)
		cin >> mine[i];
	memset(relat,false,sizeof(relat));	
	int temp;
	for (int i=1; i<=n-1; i++)
		for (int j=1; j<=n-i; j++)
		{
			cin >> temp;
			if (temp)
				relat[i][j] = true;
		}
	
	return ;
}
 
int judge (int k,int w)
{
	if(k>w)
	{
		if(relat[w][k-w])
			return true;
	}
	else
	{
		if(relat[k][w-k])
			return true;
	}
            
    return false;
}
 
void search (int k)
{
	int sum = 0, i;
	for(i=1; i<=n; i++)
		if(judge (i, k) && ! mark[i] && i != k)
		{
			mark[i] = true;
			temp_road[++sub] = i;
			search (i);
			sub --;
			mark[i] = false;
		}
    
	if(i == n + 1)
	{
		for(i=0; i<=sub; i++)
			sum += mine[temp_road[i]];
			
		if(sum > ans)
        {
			ans = sum;
			for(i=0; i<=sub; i++)
				final_road[i] = temp_road[i];
			
			longOfRoad = sub;
		}
	}
}
 
void output (void)
{
	cout << final_road[0];
	for(int i=1; i<=longOfRoad; i++)
		cout << '-' << final_road[i];
	
	cout << endl;
	cout << "MAX=" << ans;
}
 
int main()
{
	input ();
	memset(mark,false,sizeof(mark));
	for(int i=1; i<=n; i++)
	{
		sub = 0;
		temp_road[sub] = i;
		mark[i] = true;
		search (i);
		mark[i] = false;
	}
	
	output ();
	cout << endl;
	//getchar(); getchar();
	system("pause");
	return 0;
}
// dfs
