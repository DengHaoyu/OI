//
// Created by dhy on 18-8-11.
//
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node{
    int to,w,next;
}edges[30500];
int head[23000];
int tot = 0;
int n;
void add(int from,int to,int w){
    edges[++tot].next = head[from];
    edges[tot].w = w;
    edges[tot].to = to;
    head[from] = tot;
}
bool spaf(int s){//spfa板子
    int dis[2001];
    int inQueueTimes[2001];
    bool exist[2001];
    memset(exist,false, sizeof(exist));
    memset(dis,0x7f, sizeof(dis));
    memset(inQueueTimes,0, sizeof(inQueueTimes));
    queue<int> q;
    dis[s] = 0;
    inQueueTimes[s]++;
    q.push(s);
    exist[s] = true;
    int u;
    while(!q.empty()){
        u = q.front();
        q.pop();
        exist[u] = false;
        for(int i = head[u];i!=0;i = edges[i].next){
            int v = edges[i].to;
            if(dis[v]>dis[u]+edges[i].w){
                dis[v] = dis[u]+edges[i].w;

                if(!exist[v]){
                    exist[v] = true;
                    q.push(v);
                    inQueueTimes[v]++;
                }
                if(inQueueTimes[v]>n)
                    return true;
            }
        }
    }
    return false;
}

int main(void){
    int T;
    cin>>T;
    for(int i = 1;i<=T;i++){
        int m;
        cin>>n>>m;
        for(int j = 1;j<=m;j++){
            int a,b,w;
            cin>>a>>b>>w;
            if(w<0){
                add(a,b,w);
            }else{
                add(a,b,w);
                add(b,a,w);
            }
        }
        if(spaf(1)){
            cout<<"YE5"<<endl;
        }else{
            cout<<"N0"<<endl;
        }
        memset(head,0, sizeof(head));
        tot = 0;
    }
    return 0;
}