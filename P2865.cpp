//
// Created by dhy on 19-3-9.
//
#include <queue>
#include <iostream>
#include <cstring>

using namespace std;
const int MAXN = 5010;
const int MAXM = 100010;
struct edge{
    int t,w,next;
}edges[MAXM<<1];
int head[MAXN];
int top;
typedef pair<int,int> pii;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int dis[MAXN];
int dis2[MAXN];
void dijkstra(int s = 1){
    priority_queue<pii,vector<pii>,greater<pii> > q;
    memset(dis,0x3f, sizeof(dis));
    memset(dis2,0x3f, sizeof(dis2));
    q.push(make_pair(0,s));
    dis[s] = 0;
    while(!q.empty()){
        int top = q.top().second;int d = q.top().first;q.pop();
        for(int i = head[top];i;i = edges[i].next){
            int t = edges[i].t;
            if(dis[t]>d+edges[i].w){
                dis2[t] = dis[t];
                dis[t] = d+edges[i].w;
                q.push(make_pair(dis[t],t));
            }else if(dis2[t]>d+edges[i].w){
                dis2[t] = d+edges[i].w;
                q.push(make_pair(dis2[t],t));
            }
        }
    }
}

int main(){
    int n,m;cin>>n>>m;
    int f,t,w;
    for(int i = 1;i<=m;i++){
        cin>>f>>t>>w;
        add(f,t,w);add(t,f,w);
    }
    dijkstra();
    cout<<dis2[n];
}
