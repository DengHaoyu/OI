// luogu-judger-enable-o2
#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
const int MAXN = 5010;
const int MAXM = 200020;
int n,m;
double E;
double dis[MAXN];
bool vis[MAXN];
struct edge{int t,next;double w;}edges1[MAXM],edges2[MAXM];
struct node{
    int f;double w;
    bool operator<(const node&n2)const{
        return w+dis[f]>n2.w+dis[n2.f];
    }
};
int head1[MAXN],head2[MAXN];
int top1,top2;
void add1(int f,int t,double w){//正图
    edges1[++top1].next = head1[f];
    edges1[top1].t = t;
    edges1[top1].w = w;
    head1[f] = top1;
}
void add2(int f,int t,double  w){//反图
    edges2[++top2].next = head2[f];
    edges2[top2].t = t;
    edges2[top2].w = w;
    head2[f] = top2;
}
void spfa(){
    memset(vis,false , sizeof(vis));
    memset(dis,0x3f, sizeof(dis));
    queue<int> q;
    vis[n] = true;
    dis[n] = 0;
    q.push(n);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        vis[f] = false;
        for(int i = head2[f];i!=0;i = edges2[i].next){
            int t = edges2[i].t;
            if(dis[t]>dis[f]+edges2[i].w){
                dis[t] = dis[f]+edges2[i].w;
                if(!vis[t]){
                    vis[t] = true;
                    q.push(t);
                }
            }
        }
    }
}
int ct[MAXN];
bool found;
int k;
int cnt = 0;
void Astar(){
    priority_queue<node> q;
    node no;no.f = 1;no.w = 0;
    q.push(no);
    while(!q.empty()){
        node top = q.top();
        q.pop();
        if(top.w>E)return;
        ct[top.f]++;
        if(top.f == n){
            E-=top.w;
            cnt++;
            continue;
        }
        if(ct[top.f]>k)return;
        for(int i = head1[top.f];i!=0;i = edges1[i].next){
            int t = edges1[i].t;
                q.push(*new node{t,top.w+edges1[i].w});
        }
    }
}
int main(){
    cin>>n>>m>>E;
    int f,t;double e;
    for(int i = 1;i<=m;i++){
        cin>>f>>t>>e;
        add1(f,t,e);
        add2(t,f,e);
    }
    spfa();
    k = E/dis[1];
    Astar();
    cout<<cnt;
    return 0;
}