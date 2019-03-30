//
// Created by dhy on 19-1-21.
//
#include <iostream>
#include <cstring>

using namespace std;
const int MAXV = 160*50+10;
const int MAXN = 169;
int g[MAXN][MAXN];
int dp[MAXN][MAXN];
int a[MAXN],z[MAXN];
int n ,m;
int T;
int temp[MAXN*50];
int main(){
    cin>>n>>m>>T;
    for(int i = 1;i<=n;i++)cin>>a[i]>>z[i];
    for(int i = 1;i<=n;i++){
        memset(temp,0, sizeof(temp));
        for(int j = i;j<=n;j++){
            for(int k = T*(n-i+1);k>=a[j];k--){
                temp[k] = max(temp[k],temp[k-a[j]]+z[j]);
            }
            for(int k = T*(j-i+1);k>=0;k--){
                g[i][j] = max(g[i][j],temp[k]);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=min(i,m);j++){
            for(int k = j-1;k<i;k++){
                dp[i][j] = max(dp[i][j],dp[k][j-1]+g[k+1][i]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
