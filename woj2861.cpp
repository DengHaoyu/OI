//
// Created by dhy on 19-1-25.
//

#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
struct edge{int t,f,w,next;bool operator<(const edge &e2)const {return w>e2.w;}}edges[MAXN<<2];
int head[MAXN],top;
int father[MAXN][25];
int wei[MAXN][25];
int dep[MAXN];
int n ,m;
bool vis[MAXN];
int fa[MAXN];
edge edges2[MAXN<<2];
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline bool judge(int x,int y){return find(x)==find(y);}
inline void unionn(int x,int y){fa[find(y)]=find(x);}
inline void swap(int &x,int &y){x = x^y;y = y^x;x= x^y;}
void add(int f,int t,int w){
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
void kruskal(){
    sort(edges2+1,edges2+1+m);
    int cnt = 0;
    for(int i = 1;i<=m;i++){
        if(!judge(edges2[i].f,edges2[i].t)){
            unionn(edges2[i].f,edges2[i].t);
            cnt++;
            add(edges2[i].f,edges2[i].t,edges2[i].w);
            add(edges2[i].t,edges2[i].f,edges2[i].w);
        }
        if(cnt==n-1)return;
    }
}
void dfs(int fa,int x){
    vis[x] = true;dep[x] = dep[fa]+1;
    father[x][0] = fa;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(!vis[t]){
            wei[t][0] = edges[i].w;
            dfs(x,t);
        }
    }
}
void initLCA(){
    for(int i = 1;i<=n;i++)if(!vis[i])dfs(0,i);
    for(int i = 1;i<=24;i++){
        for(int j = 1;j<=n;j++){
            father[j][i] = father[father[j][i-1]][i-1];
            wei[j][i] = max(wei[j][i-1],wei[father[j][i-1]][i-1]);
        }
    }
}
int LCA(int x,int y){
    if(dep[x]<dep[y])swap(x,y);
    int ans = 0;
    int delta = dep[x]-dep[y];
    for(int i = 0;i<=24;i++){
        if(delta&(1<<i)){
            ans = max(wei[x][i],ans);
            x = father[x][i];
        }
    }
    if(x==y)return ans;
    for(int i = 24;i>=0;i--){
        if(father[x][i]!= father[y][i]){
            ans = max(wei[x][i],ans);
            ans = max(wei[y][i],ans);
            x = father[x][i], y =father[y][i];
        }
    }
    ans = max(wei[x][0],ans);
    ans = max(wei[y][0],ans);
    return ans;
}
int order[MAXN];
int limit[MAXN];
int ans[MAXN];
int rail[MAXN];
int an_ptr;
int main(){
    n = read(),m = read();int q = read();
    for(int i = 1;i<=n;i++)order[i] = read();
    for(int i = 1;i<=n;i++)limit[i] = read();
    for(int i = 1;i<=m;i++){
        int f= read(),t = read(),w = read();
        add(f,t,w);add(t,f,w);
    }
    if(q>0){
        int p = read();
        rail[1] = p;
        for(int i = 2;i<=q;i++){
            p = read();
            add(p,rail[i-1],INF);
        }
    }
    for(int i = 1;i<=n;i++)fa[i] = i;
    kruskal();
    initLCA();
    ans[1] = max(0,limit[order[1]]);
    if(limit[order[1]]<0)printf("0\n");
    for(int i = 2;i<=n;i++){
        int u = order[i];int l = LCA(u,order[i-1]);
        int k = min(l,ans[i-1]);
        ans[i] = max(0,k+limit[u]);
        if(limit[u]<0)printf("%d\n",min(k,-limit[u]));

    }
    return 0;
}
