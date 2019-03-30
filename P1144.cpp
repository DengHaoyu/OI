#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
inline int read(){
    char ch = getchar();
    int f = 1 ,x = 0;
    while(ch > '9' || ch < '0'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0';ch = getchar();}
    return x * f;
}
const int mod = 100003;
const int MAXN = 1000010;
const int MAXM = 2000010;
struct edge{int t,w,next;}edges[MAXM];
int top;
int head[MAXN];
void add(int f,int t,int w){
    edges[++top].next = head[f];
    edges[top].w = w;
    edges[top].t =t ;
    head[f] = top;
}
int dis[MAXN];
int vis[MAXN];
int ans[MAXN];
void spfa(){
    memset(dis,0x37, sizeof(dis));
    memset(vis,false, sizeof(vis));
    memset(ans,0, sizeof(ans));
    queue<int> q;
    dis[1] = 0;
    vis[1] = true;
    ans[1] = 1;
    q.push(1);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        vis[top] = false;
        for(int i = head[top];i!=0;i = edges[i].next){
            int v = edges[i].t;
            if(dis[v]>dis[top]+edges[i].w){
                dis[v]=dis[top]+edges[i].w;
                ans[v] = ans[top];
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }else if(dis[v]==dis[top]+edges[i].w){
                ans[v]+=ans[top];
                while(ans[v]>=mod){
                    ans[v]-=mod;
                }
            }
        }
    }
}
int main(void){
    int n,m;
    n = read(),m = read();
    int f,t;
    for(int i = 1;i<=m;i++){
        f = read(),t = read();
        add(f,t,1);
        add(t,f,1);
    }
    spfa();
    for(int i = 1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
