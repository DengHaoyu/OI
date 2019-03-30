//
// Created by dhy on 19-2-14.
//
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2005;
int s[MAXN];int dp[MAXN][MAXN];
int del[MAXN],add[MAXN];
int main(){
    char c;
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        cin>>c;
        s[i] = c-'a';
    }
    int d,a;
    for(int i = 1;i<=n;i++){
        cin>>c;cin>>a>>d;
        del[c-'a'] = d;
        add[c-'a'] = a;
    }
    for(int l = 2;l<=m;l++){
        for(int i = 1;i+l-1<=m;i++){
            int j = i+l-1;
            if(s[i]==s[j])dp[i][j] = dp[i+1][j-1];
            else{
                dp[i][j] = min(dp[i+1][j]+min(add[s[i]],del[s[i]]),dp[i][j-1]+min(add[s[j]],del[s[j]]));
            }
        }
    }
    cout<<dp[1][m];
    return 0;
}