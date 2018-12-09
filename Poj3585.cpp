//
// Created by dhy on 18-12-9.
//
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = (int)3e5;
struct edge{
    int t,w,next;
}edges[MAXN<<1];
int head[MAXN];
int top;
int degree[MAXN];
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int d[MAXN],F[MAXN];
bool vis[MAXN];
inline int min(int a,int b){return a<b?a:b;}
void dp(int x){
    vis[x] = true;
    d[x] = 0;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(vis[t])continue;
        dp(t);
        if(degree[t]==1){
            d[x] += edges[i].w;
        }else{
            d[x] += min(d[t],edges[i].w);
        }
    }
}
void dfs(int x){
    vis[x] = true;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(vis[t])continue;
        if(degree[x]==1)F[t] = d[t] + edges[i].w;
        else F[t] = d[t] + min(F[x]-min(d[t],edges[i].w),edges[i].w);
        dfs(t);
    }
}
int main(void){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        memset(d,0, sizeof(d));
        memset(F,0, sizeof(F));
        for(int i = 1;i<n;i++){
            int x,y,z;

            cin>>x>>y>>z;
            degree[x]++,degree[y]++;
            add(x,y,z),add(y,x,z);
        }
        dp(1);
        memset(vis,false, sizeof(vis));
        F[1] = d[1];
        dfs(1);
        int ans = 0;
        for(int i = 1;i<=n;i++)ans = -min(-ans,-F[i]);
        cout<<ans<<endl;
    }
    return 0;
}