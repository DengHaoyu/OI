//
// Created by dhy on 19-2-24.
//
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 30;
long long dp[MAXN][MAXN][MAXN];
int num[MAXN];
int ptr;
long long dfs(int pos,int pre,int sum,bool b,bool limit){
    if(pos==0){
        return (pre&1)!=(sum&1);
    }
    if(!limit&&dp[pos][pre][sum]!=-1)return dp[pos][pre][sum];
    int mx = limit?num[pos]:9;
    long long ans = 0;
    for(int i = 0;i<=mx;i++){
        if(b) {
            if (i == 0)ans += dfs(pos - 1, 0, 0, true, limit && i == mx);
            else ans += dfs(pos - 1, i & 1, 1, false, limit && i == mx);
        }else{
            if(i&1){
                if(pre&1){
                    ans+=dfs(pos-1,i&1,sum+1,false,limit&&i==mx);
                }else{
                    if(sum&1)ans+=dfs(pos-1,i&1,1,false,limit&&i==mx);
                }
            }else{
                if(pre&1){
                    if(!(sum&1))ans+=dfs(pos-1,i&1,1,false,limit&&i==mx);
                }else{
                    ans+=dfs(pos-1,i&1,sum+1,false,limit&&i==mx);
                }
            }
        }
    }
    if(!limit)dp[pos][pre][sum]=ans;
    return ans;
}
long long work(long long x){
    ptr = 0;
    if(x==0)return 0;
    while(x){
        num[++ptr] = x%10;
        x/=10;
    }
    return dfs(ptr,0,0,true,true);
}
int main(){
    int T;cin>>T;
    memset(dp,-1, sizeof(dp));
    long long L,R;
    for(int i = 1;i<=T;i++){
        cin>>L>>R;
        cout<<"Case #"<<i<<": "<<work(R)-work(L-1)<<endl;
    }
    return 0;
}