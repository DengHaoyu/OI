//
// Created by dhy on 18-8-2.
//
#include <iostream>
#include <algorithm>
using namespace std;
int a[200001];
int dp[2000001];
int main(void){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    dp[0] = 0;
    for(int i = 1;i<=n;i++)cin>>a[i],dp[i] = a[i];
    for(int i = 1;i<=n;i++){
        if(dp[i-1]+dp[i]>dp[i]){
            dp[i] = dp[i-1]+dp[i];
        }
    }
    int m = -0x7ffffff;
    for(int i = 1;i<=n;i++)m = m>dp[i]?m:dp[i];
    cout<<m;
}
