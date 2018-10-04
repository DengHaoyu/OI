//
// Created by dhy on 18-8-19.
//
#include <iostream>
using namespace std;
int dp[101][101];
int a[101][101];
int F,V;
int store[101][101];
int main(void){
    ios::sync_with_stdio(false);
    cin>>F>>V;
    for(int i = 1;i<=F;i++) {
        for (int j = 1; j <= V; j++)
            cin >> a[i][j];
    }
    for(int i = 1;i<=F;i++)
        for(int j = 1;j<=V;j++)
            dp[i][j] = -99999999;
    for(int i = 1;i<=V-F;i++)dp[1][i] = a[1][i];
    for(int i = 2;i<=F;i++){
        for(int j = i;j<=V;j++){
            for(int k = i-1;k<=j-1;k++){
                if(dp[i-1][k]+a[i][j]>dp[i][j]){
                    dp[i][j] = dp[i-1][k]+a[i][j];
                    store[i][j] = k;
                }
            }
        }
    }
    int k = 0;
    int maxx = -999999999;
    for(int i = F;i<=V;i++){
        if(dp[F][i]>maxx){
            maxx = dp[F][i];
            k = i;
        }
    }
    int d[101];
    cout<<maxx<<endl;
    for(int i = 1;i<=F;i++){
        d[i] = k;
        k = store[F-i+1][k];
    }
    for(int i = F;i>=2;i--)cout<<d[i]<<' ';

    cout<<d[1];
    return 0;
}
