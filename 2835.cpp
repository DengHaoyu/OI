//
// Created by dhy on 18-10-3.
//
#include <iostream>
using  namespace std;
const int MAXM = 200*200+10;
struct edge{
    int t,next;
}edges[MAXM*2];
int head[210];
int top;
void add(int f,int t){
    edges[++top].t = t;
    edges[top].next = head[f];
    head[f] = top;
}
int dfn_cnt;
int dfn[210];
int low[210];
int stack[210];
int stop;
int col_val=0;
bool visited[210];
void tarjan(int x){
    dfn[x] = low[x] = ++dfn_cnt;
    stack[++stop] = x;
    visited[x] = 1;
    for(int i = head[x];i!=0;i = edges[i].next){
        int v = edges[i].t;
        if(!dfn[v]){
            tarjan(v);
            low[x] = min(low[v],low[x]);
        }else if(visited[v]){
            low[x] = min(low[x],dfn[v]);
        }
    }
    if(dfn[x] == low[x]){
        ++col_val;
        visited[x] = false;
        while(stack[stop]!=x){
            visited[stack[stop--]] = false;

        }
        stop--;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int t;
    for(int i = 1;i<=n;i++){
        cin>>t;
        while(t){
            if(i!=t)
            cout<<i<<"->"<<t<<';'<<endl;
            cin>>t;
        }
    }
    for(int i = 1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    cout<<col_val<<endl;
    return 0;
}