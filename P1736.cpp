//
// Created by dhy on 19-1-5.
//
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 2510;
int map[MAXN][MAXN];
int dp[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
int n,m;
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    int ans = 0;
    cin>>n>>m;
    for(int i = 1;i<=n;i++) {
        for (int j = 1; j <= m; j++){
            cin>>map[i][j];
            if(map[i][j]==0){
                col[i][j] = col[i-1][j]+1;
                row[i][j] = row[i][j-1]+1;
            }else{
                dp[i][j] = min(dp[i-1][j-1],min(row[i][j-1],col[i-1][j]))+1;

            }
            ans = max(ans,dp[i][j]);
        }
    }
    memset(dp,0, sizeof(dp));
    memset(row,0, sizeof(row));
    memset(col,0, sizeof(col));
    for(int i = 1;i<=n;i++)
        for(int j = m;j>=1;j--){
            if(map[i][j]==0){
                col[i][j] = col[i-1][j]+1;
                row[i][j] = row[i][j+1]+1;
            }else{
                dp[i][j] = min(dp[i-1][j+1],min(row[i][j+1],col[i-1][j]))+1;
            }
                ans = max(ans,dp[i][j]);
        }
        cout<<ans;

    return 0;
};
