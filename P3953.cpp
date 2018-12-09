//
// Created by dhy on 18-11-4.
//
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-') f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXM = 200010;
const int MAXN = 100010;
struct edge{
    int t,w,next;
}edges[MAXM],edges1[MAXM];
int head[MAXN],head1[MAXM];
int top,top1;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
void add1(int f,int t,int w){
    edges1[++top1].next = head1[f];
    edges1[top1].t = t;
    edges1[top1].w = w;
    head1[f] = top;
}
int dis[MAXN];
bool vis[MAXN];
int n,m,k,mod;
void spfa(){
    memset(dis,0x3f, sizeof(dis));
    memset(vis,false, sizeof(vis));
    dis[n] = 0;
    vis[n] = true;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        vis[f] = false;
        for(int i = head[f];i!=0;i = edges[i].next){
            int t = edges[i].t;
            if(dis[t]>dis[f]+edges[i].w){
                dis[t] = dis[f]+edges[i].w;
                if(!vis[t]){
                    vis[t] = true;
                    q.push(t);
                }
            }
        }
    }
}
struct p{
    int f,w;
    bool operator<(const p&p2)const{
        return w+dis[f]>p2.w+dis[p2.f];
    }
};
int cnt = 0;
bool unlim = false;
void AStar(){
    p f = {1,0};
    priority_queue<p> q;
    q.push(f);
    int shortest = 0;
    while(!q.empty()){
        p top = q.top();
        q.pop();
        if(top.w+dis[top.f]>shortest+k&&shortest!=0){
            return;
        }
        if(f.f == n){
            if(shortest==0)shortest = f.w;
            cnt++;
            if(cnt>mod)cnt-=mod;
        }
        for(int i = head1[f.f];i!=0;i = edges1[i].next){
            int t = edges1[i].t;
            if(f.w+dis[t]>shortest+k&&shortest!=0){
                continue;
            }
            if(shortest!=0&&edges1[i].w==0){
                unlim = true;
                return;
            }
            p te;
            te.f = t;
            te.w = f.w+edges1[i].w;
            q.push(te);
        }
    }
}
int main(){
    int T = read();

    int f,t,w;
    while(T--) {
        cnt = 0;
        unlim = false;
        top = top1 = 0;
        n = read(),m = read(),k = read(),mod = read();
        for (int i = 1; i <= m; i++) {
            f = read(), t = read(), w = read();
            add1(f,t,w);
            add(t,f,w);
        }
        spfa();
        AStar();
        if(unlim){
            printf("%d\n",-1);
        }else{
            printf("%d\n",cnt);
        }
    }
    return 0;
}