//
// Created by dhy on 18-9-24.
//
//tarjan find cut point
int stack[10000];
int dfn[10000];
int low[10000];
int stop;
int dfn_cnt;
bool visited[1000];
bool iscut[1000];
void tarjan(int x,int fa){
    int child = 0;
    dfn[x]=++dfn_cnt;
    low[x] = dfn[x];
    visited[x] = true;
    stack[++stop] = x;
    for(int j = x;j!=0;j = edges[j].next){
        int u = edges[j].t;
        if(!dfn[u]){
            child++;
            tarjan(u,x);
            low[x] = min(low[x],low[u]);
            if(low[u]>=dfn[x]&&u!=fa){
                iscut[x] = true;
            }
            if(u==fa)child++;
        }else if(visited[u]){
            low[x] = min(low[x],dfn[u]);
        }
    }
    if(child>=2&&x==fa)iscut[x]=true;
}
