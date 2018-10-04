//
// Created by dhy on 18-8-2.
//
#include <iostream>
#include <algorithm>
using namespace std;
int bin[45][45][45][45];
bool vis[45][45][45][45];
int w[400],p[5] = {0};
int n;
int dp(int a,int b,int c,int d){
    if(a==p[1]&&b==p[2]&&c==p[3]&&d==p[4]){
        return w[n];
    }
    if(vis[a][b][c][d])return bin[a][b][c][d];

    int now = a+2*b+3*c+4*d;

    if(a<p[1])bin[a][b][c][d] = max(bin[a][b][c][d],dp(a+1,b,c,d));
    if(b<p[2])bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b+1,c,d));
    if(c<p[3])bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b,c+1,d));
    if(d<p[4])bin[a][b][c][d] = max(bin[a][b][c][d],dp(a,b,c,d+1));
    bin[a][b][c][d]+=w[now+1];
    vis[a][b][c][d] = 1;
    return bin[a][b][c][d];
}
int main(void){
    int M;
    cin>>n>>M;
    int t;
    for(int i = 1;i<=n;i++)cin>>w[i];
    for(int i = 1;i<=M;i++){
        cin>>t;
        p[t]++;
    }
    cout<<dp(0,0,0,0);
}
