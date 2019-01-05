//
// Created by dhy on 18-12-30.
//
#include <iostream>
#include <cstring>
#include <cmath>
int dp[2010][2010];
int T,MAXP,W,ap,bp,as,bs;
int q[2010];
using namespace std;
int main(void){
    cin>>T>>MAXP>>W;
    memset(dp,128, sizeof(dp));
    for(int i = 1;i<=T;i++){
        cin>>ap>>bp>>as>>bs;
        //statement 1 just buy it
        for(int j = 0;j<=as;j++)
            dp[i][j] = -ap*j;
        for(int j = 0;j<=MAXP;j++)dp[i][j] = max(dp[i][j],dp[i-1][j]);
        if(i<=W)continue;
        //statement 3
        int l = 1,r = 0;
        for(int j = 0;j<=MAXP;j++){
            while(l<=r&&q[l]<j-as)l++;
            while(l<=r&&dp[i-1-W][q[r]]+q[r]*ap<=dp[i-1-W][j]+j*ap)r--;
            q[++r] = j;
            if(l<=r)dp[i][j] = max(dp[i][j],dp[i-1-W][q[l]]+q[l]*ap-j*ap);
        }
        l = 1,r = 0;
        for(int j = MAXP;j>=0;j--){
            while(l<=r&&q[l]>j+bs)l++;
            while(l<=r&&dp[i-W-1][q[r]]+q[r]*bp<=dp[i-W-1][j]+j*bp)r--;
            q[++r] = j;
            if(l<=r)dp[i][j] = max(dp[i][j],dp[i-W-1][q[l]]+q[l]*bp-j*bp);
        }
    }
    int ans = -99999999;
    for(int i = 1;i<=MAXP;i++)ans = max(dp[T][i],ans);
    cout<<dp[T][0];
}
