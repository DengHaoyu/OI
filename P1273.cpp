
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 3010;
const int MAXM = 3010<<1;
struct edge{
    int t,w,next;
}edges[MAXM];
int head[MAXN];
int top;
void add(int f,int t,int w){
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int dp[MAXN][MAXN];
int son[MAXN];
int n,m;
int cost[MAXN];
void dfs(int f,int fa){
    dp[f][0] = 0;
    if(f>=n-m+1){son[f] = 1;dp[f][1] = cost[f];return;}
    son[f] = 0;
    for(int i = head[f];i!=0;i = edges[i].next){
        int t = edges[i].t;
        if(t==fa)continue;
        dfs(t,f);son[f]+=son[t];
        for(int j = son[f];j>=0;j--){
            for(int k = son[t];k>=0;k--){
                dp[f][j] = max(dp[f][j],dp[f][j-k]+dp[t][k]-edges[i].w);
            }
        }

    }
}
int main(){
    cin>>n>>m;
    int k,a,c;
    for(int i = 1;i<=n-m;i++){
        cin>>k;
        for(int j = 1;j<=k;j++){
            cin>>a>>c;
            add(i,a,c);
        }
    }
    for(int i = n-m+1;i<=n;i++){
        cin>>cost[i];
    }
    memset(dp,0xc0, sizeof(dp));
    dfs(1,0);
    int ans = 0;
    for(int i = 1;i<=m;i++){
        if(dp[1][i]>=0){
            ans = i;
        }
    }
    cout<<ans;
    return 0;
};


