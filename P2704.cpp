//
// Created by dhy on 18-12-16.
//
#include <cstring>
#include <iostream>
using namespace std;
int dp[110][77][77];
int S[100];
int map[101];
int cnt[101];
int top;
int n,m;
int getBit(int x){
    int c = 0;
    while(x)c++,x-=x&-x;
    return c;
}
bool ok(int x){
    if(x&(x<<1))return false;
    if(x&(x<<2))return false;
    return true;
}
void init(){
    int end = 1<<m;
    for(int i = 0;i<end;i++)if(ok(i))S[top] = i,cnt[top++] = getBit(i);
}
bool valid(int l,int x){
    if(map[l]&x)return false;
    return true;
}
inline int max(int a,int b){return a>b?a:b;}
int work(){
    memset(dp,-1, sizeof(dp));
    dp[0][0][0] = 0;
    int ans = 0;
    for(int i = 0;i<top;i++){
        if(valid(1,S[i])){
            dp[1][i][0] = cnt[i];
            ans = max(ans,dp[1][i][0]);
        }
    }
    for(int i = 2;i<=n;i++){
        for(int j = 0;j<top;j++){
            if(valid(i,S[j]))
                for(int k = 0;k<top;k++){//i-1
                    if(valid(i-1,S[k])&&(S[j]&S[k])==0){
                        int last = 0;
                        for(int l = 0;l<top;l++){//i-2
                            if(dp[i-1][k][l]!=-1&&(S[l]&S[j])==0&&valid(i-2,S[l])){
                                last = max(last,dp[i-1][k][l]);
                            }
                        }
                        dp[i][j][k] = max(dp[i][j][k],last+cnt[j]);
                        if(i==n)ans = max(ans,dp[i][j][k]);
                    }
            }
        }
    }
    return ans;

}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            if (t == 'H')map[i] |= (1 << (m - 1 - j));
        }
    }
    init();
    cout<<work()<<endl;
    return 0;
}