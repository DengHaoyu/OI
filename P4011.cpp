//
// Created by dhy on 19-3-9.
//

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
const int MAXN = 12*12*1024+20;
const int MAXM = MAXN*4;
struct edge{int t,w,next;}edges[MAXM<<1];
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
typedef pair<int ,int> pii;
vector<pii> keys[12];
int G[1010][1010];int m,n;int layer,keyen;
bool hasKey[15];
int num(int i,int j){
    return (i-1)*m+j;
}
int sze;
void build(){
    for(int k = 0;k<layer;k++){
        for(int p = 1;p<=keyen;p++){
            hasKey[p] = k&(1<<p-1);
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=m;j++){
                    int x = num(i,j);
                    int y = num(i,j+1);
                    if(G[x][y]!=-1&&j<m){
                        if(hasKey[G[x][y]]||G[x][y]==0){
                            add(k*sze+x,k*sze+y,1);
                            add(k*sze+y,k*sze+x,1);
                        }
                    }
                    y = num(i+1,j);
                    if(G[x][y]!=-1&&i<n){
                        if(hasKey[G[x][y]]||G[x][y]==0){
                            add(k*sze+x,k*sze+y,1);
                            add(k*sze+y,k*sze+x,1);
                        }
                    }
                }
            }
        }

        for(int i = 1;i<=keyen;i++){
            if(!vis[i]){
                int t = k|(1<<i-1);
                for(int j = 0;j<keys[i].size();j++){
                    int x = num(keys[i][j].first,keys[i][j].second);
                    add(k*sze+x,t*sze+x,0);
                }
            }
        }
    }
}
void spfa(){
    memset(dis,0x3f, sizeof(dis));
    memset(vis,false, sizeof(vis));
    queue<int> q;
    dis[1] = 0;
    vis[1] = true;
    q.push(1);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        vis[top] = false;
        for(int i = head[top];i!=0;i = edges[i].next){
            int v = edges[i].t;
            if(dis[v]>dis[top]+edges[i].w){
                dis[v]=dis[top]+edges[i].w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
}
int main(void){
    n = read(),m = read(),keyen = read();
    sze = m*n;layer = 1<<keyen;
    int x1,y1,x2,y2,g;
    int k = read();
    for(int i = 1;i<=k;i++){
        x1 = read(),y1 = read(),x2 = read(),y2 = read(),g = read();
        if(g==0)g--;
        G[num(x1,y1)][num(x2,y2)] = G[num(x2,y2)][num(x1,y1)] = g;

    }
    int r = read();
    for(int i = 1;i<=r;i++){
        x1 = read(),y1 = read();
        int p = read();
        keys[p].push_back(make_pair(x1,y1));
    }
    build();
    spfa();
    int ans = 0x3f3f3f3f;
    int T = num(n,m);
    for(int i = 0;i<layer;i++)ans = min(ans,dis[i*sze+T]);
    printf("%d",ans<0x3f3f3f3f?ans:-1);
    return 0;
}
