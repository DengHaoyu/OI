//
// Created by dhy on 19-1-20.
//

#include <iostream>
using namespace std;
const int MAXN = 5010;
const int mod = (int)1e9+7;
char c[MAXN];
int hsh[MAXN][MAXN];
long long dp[MAXN][MAXN];
int cmp(int a,int b){
    if(c[a]==c[b])return 0;
    if(c[a]<c[b])return -1;
    else return 1;
}
int cmp1(int a,int b,int i,int j){
    if(c[a]!=c[i])return cmp(a,i);
    if(hsh[a][b]==hsh[i][j]){//can't transfer when equal
        return 0;
    }
    int l = 1,r = b-a;
    while(l<r){
        int mid = (l+r)>>1;
        if(hsh[a][a+mid]==hsh[i][i+mid])l = mid+1;
        else r = mid;
    }
    return cmp(a+l,i+l);
}
int work(int l,int r){
    return ((dp[l][r]-dp[l-1][r])%mod+mod)%mod;
}
int n;
int main(){
    cin>>n;
    cin>>c+1;
    for(int i = 1;i<=n;i++){
        hsh[i][i] = c[i]-'0';
        for(int j = i+1;j<=n;j++){
            hsh[i][j] = (hsh[i][j-1]*10+c[j]-'0')%mod;
        }
    }
    for(int i = 1;i<=n;i++)dp[1][i] = 1;

    for(int i = 2;i<=n;i++){
        for(int j = i;j<=n;j++){
            int r = i-1,l = r-j+i;
            dp[i][j] = ((dp[r][r]-dp[max(l,0)][r])%mod+mod)%mod;
            if(l>=1&&cmp1(l,r,i,j)==-1){
                dp[i][j] = (dp[i][j]+work(l,r))%mod;
            }
            if(c[i]=='0')dp[i][j] = 0;
            dp[i][j] = (dp[i-1][j]+dp[i][j])%mod;
        }
    }
    cout<<dp[n][n];
    return 0;
}