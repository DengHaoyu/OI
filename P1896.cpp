//
// Created by dhy on 18-12-16.
//
#include <cstring>
#include <iostream>
using namespace std;
int n,m;
int dp[15][1025][100];
int S[120],cnt[120];
int top;
int getBit(int x){
    int cnt = 0;
    while(x)cnt++,x-=x&-x;
    return cnt;
}
bool valid(int x){
    if(x&(x<<1))return false;
    return true;
}
int main() {
    cin >> n >> m;
    int end = 1<<n;
    for(int i = 0;i<end;i++)if(valid(i))S[++top] = i,cnt[top] = getBit(i),dp[1][i][cnt[top]]=1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=top;j++){
            int x = S[j];
            for(int k = 1;k<=top;k++){
                int y = S[k];
                if((x&y)||(x&(y<<1))||(x&(y>>1)))continue;
                for(int l = 0;l<=m;l++)dp[i][j][cnt[j]+l]+=dp[i-1][k][l];
            }
        }
    }
    long long ans = 0;
    for(int i = 1;i<=top;i++)ans+=dp[n][i][m];
    cout<<ans;
    return 0;
}