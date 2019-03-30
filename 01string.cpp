//
// Created by dhy on 19-2-16.
//
#include <iostream>
using namespace std;
const int MAXN = 5000;
long long dp[MAXN][2];
long long sum[MAXN][2];
int mod = (int)1e9+7;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i = 1;i<=k;i++){
        dp[i][0] = dp[i][1] = 1;
        sum[i][0] = sum[i-1][0]+1;
        sum[i][1] = sum[i-1][1]+1;
    }
    for(int i = k+1;i<=n;i++){
        dp[i][1] = sum[i-k+1][0];
        dp[i][0] = sum[i-k+1][1];
        sum[i][1] = sum[i-1][1]+dp[i][1]%mod;
        sum[i][0] = sum[i-1][0]+dp[i][0]%mod;
    }
    cout<<dp[n][0]+dp[n][1]%mod;
    return 0;
}
