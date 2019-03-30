//
// Created by dhy on 19-1-22.
//
#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int MAXN = 12*12*1024+10;
const int MAXM = MAXN*4;
int p,n,m;
int states;
int map[1001][1001];
struct edge{int w,t,next;}edges[MAXM];
int head[MAXN],top;
int M;
vector<pair<int,int> > keys[12];
void add(int f,int t,int w){
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+(c^'0');c = getchar(); }
    return x*f;
}
int dis[MAXN];
bool vis[MAXN];
void spfa(int s){
    memset(dis,0x3f, sizeof(dis));
    memset(vis,false, sizeof(vis));
    queue<int>q;
    dis[s] = 0,vis[s] = true;
    q.push(s);
    while(!q.empty()){
        int top = q.front();q.pop();
        vis[top] = false;
        for(int i = head[top];i;i = edges[i].next){
            int t = edges[i].t;
            if(dis[t]>dis[top]+edges[i].w){
                dis[t] = dis[top]+edges[i].w;
                if(!vis[t])vis[t] = true,q.push(t);
            }
        }
    }
}
void init(){
    states=1<<p;
}
int getId(int i,int j){return m*(i-1)+j;}
void build(){
    bool vis[14] = {};
    for(int k = 0;k<states;k++){
        for(int key = 1;key<=p;key++){
            vis[key] = k&(1<<key-1);
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    int x = getId(i,j),y = getId(i,j+1);
                    if(j<m&&map[x][y]!=-1){
                        if(map[x][y]==0||vis[map[x][y]]){
                            add(k*M+x,k*M+y,1);
                            add(k*M+y,k*M+x,1);
                        }
                    }
                    y = getId(i+1,j);
                    if(i<n&&map[x][y]!=-1){
                        if(map[x][y]==0||vis[map[x][y]]){
                            add(k*M+x,k*M+y,1);
                            add(k*M+y,k*M+x,1);
                        }
                    }
                }
            }
        }
        for(int i = 1;i<=p;i++){
            if(!vis[i]){
                int t = k+(1<<i-1);
                for(int j = 0;j<keys[i].size();j++){
                    int x = getId(keys[i][j].first,keys[i][j].second);
                    add(k*M+x,t*M+x,0);
                }
            }
        }
    }
}
int main(){
    n = read(),m = read(),p = read();
    int k = read();
    for(int i = 1;i<=k;i++){
        int x1 = read(),y1 = read(), x2 = read(),y2 = read();
        int gi = read();
        if(gi==0)gi = -1;
        map[getId(x1,y1)][getId(x2,y2)] = gi;map[getId(x2,y2)][getId(x1,y1)] = gi;
    }
    int r = read();
    for(int i = 1;i<=r;i++){
        int x = read(),y = read(),t = read();
        keys[t].push_back(make_pair(x,y));
    }
    init();
    M = n*m;
    build();
    int N = M*states;
    int ans = 0x3f3f3f3f;
    spfa(getId(1,1));
    for(int i = 0;i<=states;i++){
        ans = min(ans,dis[i*M+getId(n,m)]);
    }
    printf("%d",ans<0x3f3f3f3f?ans:-1);
    return 0;
}