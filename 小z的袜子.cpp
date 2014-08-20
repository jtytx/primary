#include <iostream>    
#include <cstdio>    
#include <algorithm>    
#include <vector>  
#include <cstring>  
#define lowbit(x) (x&(-x))   
#define LL long long   
using namespace std;    
const int N = 50005;    
struct Point{    
    int x,y,id;    
    bool operator<(const Point p)const{    
        return x!=p.x?x<p.x:y<p.y;    
    }    
}p[N],pp[N];    
//��״���飬��(y-x)���ڵ�ǰ�ģ�����y+x��С��  
struct BIT{    
    int min_val,pos;    
    void init(){    
        min_val=(1<<30);    
        pos=-1;    
    }    
}bit[N];    
//������Ч�ߣ�Kruskal  
struct Edge{    
    int u,v,d;    
    bool operator<(const Edge e)const{    
        return d<e.d;    
    }    
}e[N<<2];    
//ǰ����  
struct Graph{  
    int v,next;  
}edge[N<<1];  
int n,m,tot,pre[N];    
int total,start[N];  
int find(int x){    
    return pre[x]=(x==pre[x]?x:find(pre[x]));    
}    
inline int dist(int i,int j){    
    return abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);    
}    
inline void addedge(int u,int v,int d){    
    e[tot].u=u;    
    e[tot].v=v;    
    e[tot++].d=d;    
}    
inline void _add(int u,int v){  
    edge[total].v=v;  
    edge[total].next=start[u];  
    start[u]=total++;  
}  
inline void update(int x,int val,int pos){    
    for(int i=x;i>=1;i-=lowbit(i))    
        if(val<bit[i].min_val)    
            bit[i].min_val=val,bit[i].pos=pos;    
}    
inline int ask(int x,int m){    
    int min_val=(1<<30),pos=-1;    
    for(int i=x;i<=m;i+=lowbit(i))    
        if(bit[i].min_val<min_val)    
            min_val=bit[i].min_val,pos=bit[i].pos;    
    return pos;    
}    
inline void Manhattan_minimum_spanning_tree(int n,Point *p){    
    int a[N],b[N];    
    for(int dir=0;dir<4;dir++){    
        //4������任    
        if(dir==1||dir==3){    
            for(int i=0;i<n;i++)    
                swap(p[i].x,p[i].y);    
        }    
        else if(dir==2){    
            for(int i=0;i<n;i++){    
                p[i].x=-p[i].x;    
            }    
        }    
        sort(p,p+n);    
        for(int i=0;i<n;i++){    
            a[i]=b[i]=p[i].y-p[i].x;    
        }    
        sort(b,b+n);    
        int m=unique(b,b+n)-b;    
        for(int i=1;i<=m;i++)    
            bit[i].init();    
        for(int i=n-1;i>=0;i--){    
            int pos=lower_bound(b,b+m,a[i])-b+1;   //BIT�д�1��ʼ    
            int ans=ask(pos,m);    
            if(ans!=-1)    
                addedge(p[i].id,p[ans].id,dist(i,ans));    
            update(pos,p[i].x+p[i].y,i);    
        }    
    }    
    sort(e,e+tot);    
    for(int i=0;i<n;i++)    
        pre[i]=i;    
    for(int i=0;i<tot;i++){    
        int u=e[i].u,v=e[i].v;    
        int fa=find(u),fb=find(v);    
        if(fa!=fb){   
            pre[fa]=fb;    
            _add(u,v);  
            _add(v,u);  
        }    
    }    
}    
LL gcd(LL a,LL b){  
    return b==0?a:gcd(b,a%b);  
}  
LL up[N],down[N];  
LL ans;  
int col[N],vis[N]={0};  
int cnt[N]={0};   //��¼ÿ����ɫ���ֵĴ���  
inline void add(int l,int r){  
    for(int i=l;i<=r;i++){  
        int c=col[i];  
        ans-=(LL)cnt[c]*(cnt[c]-1)/2;  
        cnt[c]++;  
        ans+=(LL)cnt[c]*(cnt[c]-1)/2;  
    }  
}  
inline void del(int l,int r){  
    for(int i=l;i<=r;i++){  
        int c=col[i];  
        ans-=(LL)cnt[c]*(cnt[c]-1)/2;  
        cnt[c]--;  
        ans+=(LL)cnt[c]*(cnt[c]-1)/2;  
    }  
}  
//[l1,r1]ǰһ������ [l2,r2]��ǰ����  
void dfs(int l1,int r1,int l2,int r2,int idx,int pre){    
  
    if(l2<l1) add(l2,l1-1);  
    if(r2>r1) add(r1+1,r2);  
    if(l2>l1) del(l1,l2-1);  
    if(r2<r1) del(r2+1,r1);  
    up[pp[idx].id]=ans;  
    vis[idx]=1;  
    for(int i=start[idx];i!=-1;i=edge[i].next){  
        int v=edge[i].v;  
        if(vis[v]) continue;  
        dfs(l2,r2,pp[v].x,pp[v].y,v,idx);  
    }  
    if(l2<l1) del(l2,l1-1);  
    if(r2>r1) del(r1+1,r2);  
    if(l2>l1) add(l1,l2-1);  
    if(r2<r1) add(r2+1,r1);  
}  
int main(){    
    //freopen("input.txt","r",stdin);  
    scanf("%d%d",&n,&m);    
    tot=total=0;  
    memset(start,-1,sizeof(start));    
    for(int i=1;i<=n;i++)  
        scanf("%d",&col[i]);  
    for(int i=0;i<m;i++){    
        scanf("%d%d",&p[i].x,&p[i].y);    
        down[i]=(LL)(p[i].y-p[i].x+1)*(p[i].y-p[i].x)/2;  
        p[i].id=i;    
        pp[i]=p[i];   //����һ�ݣ����ں���DFS������֮��id����  
    }   
    Manhattan_minimum_spanning_tree(m,p);  
    for(int i=0;i<m;i++){  
        p[i].y=-p[i].y;  
    }  
    dfs(2,1,pp[0].x,pp[0].y,0,-1);  
    for(int i=0;i<m;i++){  
        LL g=gcd(up[i],down[i]);  
        printf("%lld/%lld\n",up[i]/g,down[i]/g);  
    } 
    system("pause"); 
    return 0;    
}    
