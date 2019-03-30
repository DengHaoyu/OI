//
// Created by dhy on 19-3-9.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 600;
const int MAXM = 1100;
struct edge{
    int t,w,next;
}edges[MAXM<<1];
int head[MAXN];
int top;
int dp[MAXN][MAXN];
int val[MAXN],cst[MAXN];
int col_val[MAXN],col_cst[MAXN];
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int color[MAXN],dfn[MAXN],low[MAXN];
int dfn_cnt,col;
stack<int> stk;
bool vis[MAXN];
int n,m;
int fa[MAXN],son[MAXN];
int tree[MAXN][2];
void tarjan(int x){
    dfn[x] = low[x] = ++dfn_cnt;
    stk.push(x);vis[x] = true;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(!dfn[t]){
            tarjan(t);
            low[x] = min(low[x],low[t]);
        }else if(vis[t]){
            low[x] = min(low[x],dfn[t]);
        }
    }
    if(low[x]==dfn[x]){
        color[x] = ++col;
        vis[x] = false;
        while(stk.top()!=x){
            color[stk.top()]=col;
            vis[stk.top()] = false;
            stk.pop();
        }
        stk.pop();
    }
}
vector<int> G[MAXN];
int dfs(int x,int v){
    if(!x||!v)return 0;
    if(dp[x][v]!=-1)return dp[x][v];
    dp[x][v] = dp(tree[x][1],v);
    for(int i = 0;i<=v-col_val[fa[x]];i++){
        dp[x][v] = max(dp[x][v],dfs(tree[x][0],i)+dfs(tree[x][1],v-i-col_val[fa[x]])+col_val[x]);
    }
    return dp[x][v];
}
int degree[MAXN];
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        cin>>cst[i];
    for(int i = 1;i<=n;i++)
        cin>>val[i];
    for(int i = 1;i<=n;i++){
        int t;cin>>t;
        if(t==0)continue;
        add(t,i,0);
    }
    for(int i = 1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i = 1;i<=n;i++){
        for(int j = head[i];j;j = edges[j].next){
            int t = edges[j].t;
            if(color[i]==color[t])continue;
            degree[color[t]]++;
            G[color[i]].push_back(color[t]);
        }
        col_cst[color[i]]+=cst[i];
        col_val[color[i]]+=val[i];
    }
    for(int i = 1;i<=col;i++)if(degree[i]==0)G[0].push_back(i);

    dfs(0,0);
    cout<<dp[0][m];
    return 0;
}