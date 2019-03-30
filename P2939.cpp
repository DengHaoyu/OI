//
// Created by dhy on 19-1-21.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXN = 220010;
const int MAXM = 4200010;
struct edge{
    int t,w,next;
}edges[MAXM];
int head[MAXN];
int top;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int dis[MAXN];
bool vis[MAXN];

struct node{
    int f,w;
    bool operator<(const node &n2)const{
        return w>n2.w;
    }
};
void dijkstra(){
    priority_queue<node> q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,false,sizeof(vis));
    node temp;
    temp.f = 1;
    dis[1] = 0;
    temp.w = 1;
    q.push(temp);
    while(!q.empty()){
        node top = q.top();
        q.pop();
        if(vis[top.f])continue;
        vis[top.f] = true;
        for(int i = head[top.f];i!=0;i = edges[i].next){
            int t = edges[i].t;
            if(dis[t]>dis[top.f]+edges[i].w){
                dis[t]=dis[top.f]+edges[i].w;
                temp.f = t;
                temp.w = dis[top.f]+edges[i].w;
                q.push(temp);
            }
        }
    }
}
int main(){
    int k;
    int n = read();int m = read();
    k = read();
    for(int i = 1;i<=m;i++){
        int f =read(),t = read(),w = read();
        add(f,t,w);
        add(t,f,w);//0层
        for(int j = 1;j<=k;j++){
            add(j*n+f,j*n+t,w);
            add(j*n+t,j*n+f,w);
            add((j-1)*n+f,j*n+t,0);
            add((j-1)*n+t,j*n+f,0);
        }
    }
    dijkstra();
    int ans = 0x3f3f3f3f;
    for(int i = 0;i<=k;i++){
        ans = min(ans,dis[i*n+n]);
    }
    printf("%d",ans);
    return 0;
}
