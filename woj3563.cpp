//
// Created by dhy on 19-1-26.
//
#include <iostream>
using namespace std;
const long long mod = (long long)1e9+7;
long long pow(long long base,int p){
    long long ans = 1;
    while(p){
        if(p&1)ans = ans*base%mod;
        base = base * base %mod;
        p>>=1;
    }
    return ans;
}
long long dp[(int)1e6+10];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    dp[0] = 1;
    long long sum = 0;
    for(int i = 1;i<k;i++){
        dp[i] = dp[i-1]*m%mod;
        sum = (sum+dp[i])%mod;
    }
    for(int i = k;i<=n;i++){
       dp[i] = sum*(m-1)%mod;sum+=dp[i]-dp[i-k+1];
       sum = (sum%mod+mod)%mod;

    }
    long long ans = ((pow(m,n)-dp[n])%mod+mod)%mod;
    cout<<ans;
    return 0;

}