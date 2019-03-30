//
// Created by dhy on 19-2-4.
//
#include <iostream>
using namespace std;
const int MAXN = (int)1e5+10;
int dp[MAXN][2];
const int mod = 5000011;
int main(){
    int n,k;
    cin>>n>>k;
    dp[1][1] = dp[1][0] = 1;
    for(int i = 1;i<k;i++)dp[i][1] = 1;
    for(int i = 2;i<=n;i++){
        dp[i][0] = (dp[i-1][0]+dp[i-1][1])%mod;
        if(i-k>=1)dp[i][1] = dp[i-k][0];else dp[i][1] = 1;
    }
    cout<<(dp[n][1]+dp[n][0])%mod;
    return 0;
}
