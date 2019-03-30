//
// Created by dhy on 19-2-13.
//
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 5010;
int a[MAXN];
int dp[MAXN][MAXN][2];
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int n;cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    n = unique(a+1,a+n+1)-a-1;
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i<=n;i++)
        dp[i][i][0] = dp[i][i][1] = 0;
    for(int j = 1;j<=n;j++){
        for(int i = j;i>=1;i--){
            for(int col = 0;col<2;col++){
                int c = (col==0?a[i]:a[j]);
                if(i>1)dp[i-1][j][0] = min(dp[i-1][j][0],dp[i][j][col]+(c!=a[i-1]));
                if(j<n)dp[i][j+1][1] = min(dp[i][j+1][1],dp[i][j][col]+(c!=a[j+1]));
            }
        }
    }
    cout<<min(dp[1][n][0],dp[1][n][1]);
    return 0;
}
