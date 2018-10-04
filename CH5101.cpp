//
// Created by dhy on 18-8-18.
//
#include <algorithm>
#include <iostream>
using namespace std;
int a[3001];
int b[3001];
int dp[3001][3001];
int rec[3001];
int top = 0;
int main(void){
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)cin>>b[i];
    int val = 0;
    for(int i = 1;i<=n;i++){
        val = dp[i-1][0];
        for(int j = 1;j<=n;j++){
            if(a[i]==b[j]) {
                dp[i][j] = val+1;
                rec[++top] = a[i];
            }
            else dp[i][j] = dp[i-1][j];
            if(b[j]<a[i])val = max(val,dp[i-1][j]);
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)ans = max(ans,dp[n][i]);
    cout<<ans<<endl;
//    for(int i = 1;i<=top;i++)cout<<rec[i]<<' ';
    return 0;
}
