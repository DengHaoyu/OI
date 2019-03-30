//
// Created by dhy on 19-3-3.
//

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 310;
struct edge{
    int t,w,next;
}edges[MAXN<<1];
int head[MAXN];
int top;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int dp[MAXN][MAXN][2];
int n,m,k;
int son[MAXN];
int temp[MAXN][2];
void dfs(int x,int fa){
    son[x] = 1;
    dp[x][0][0] = dp[x][1][1] = 0;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(t==fa)continue;
        dfs(t,x);
        son[x]+=son[t];
        memcpy(temp,dp[x], sizeof(dp[x]));
        memset(dp[x],127/3, sizeof(dp[x]));
        for(int j = son[x];j+1;j--){
            if(j)
            for(int k = j-1;k+1;k--) {
                dp[x][j][1] = min(dp[t][k][1] + temp[j - k][1] + edges[i].w, dp[t][k][0] + temp[j - k][1]);
            }
            for(int k = j;k+1;k--) {
                dp[x][j][0] = dp[t][k][1]+temp[j-k][0];
                if(m==2){
                    dp[x][j][0] = min(dp[x][j][0],temp[j-k][0]+dp[t][k][0]+edges[i].w);
                }else{
                    dp[x][j][0] = min(dp[x][j][0],temp[j-k][0]+dp[t][k][0]);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>k;
    if(n-k<m-1){
        cout<<-1;return 0;
    }
    int f,t,w;
    for(int i = 1;i<n;i++){
        cin>>f>>t>>w;
        add(f,t,w);add(t,f,w);
    }
    memset(dp,0x3f, sizeof(dp));
    dfs(1,0);
    cout<<dp[1][k][1];
    return 0;
}