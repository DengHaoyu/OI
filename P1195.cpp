//
// Created by dhy on 18-8-7.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int u,v,w;
}edges[100001];
int total = 0;
void add(int u,int v,int w){
    edges[++total].u = u;
    edges[total].w = w;
    edges[total].v = v;
}
bool cmp(const edge &e1,const edge &e2){
    return e1.w<e2.w;
}
int father[100001];
int find(int x){
    if(father[x]!=x)father[x] = find(father[x]);
    return father[x];
}
void unionn(int x,int y){
    x = find(x);
    y = find(y);
    father[y] = x;
}
bool judge(int x,int y){
    return find(x)==find(y);
}
int main(void){
    int N,M,K;
    ios::sync_with_stdio(false);
    cin>>N>>M>>K;
    for(int i = 1;i<=M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    sort(edges+1,edges+total+1,cmp);
    K = N-K;
    int cost = 0;
    for(int i = 1;i<=N;father[i] = i,i++);
    for(int i = 1;i<=M;i++){
        if(!judge(edges[i].u,edges[i].v)){
            unionn(edges[i].u,edges[i].v);
            cost+=edges[i].w;
            K--;
        }
        if(!K)break;
    }
    if(K)cout<<"No Answer";
    else cout<<cost;
    return 0;
}
