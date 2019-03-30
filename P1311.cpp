//
// Created by dhy on 19-2-10.
//
#include <iostream>
using namespace std;
const int MAXN = 200010;
int color[MAXN][51];int last[MAXN];
int a[MAXN];
int temp;
int main(){
    int n,k,p;cin>>n>>k>>p;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>temp;
        for(int j = 0;j<k;j++)color[i][j] = color[i-1][j];
        color[i][a[i]]++;
        if(temp<=p)last[i] = i;
        else last[i] = last[i-1];

    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans+=color[last[i]][a[i]];
        if(last[i]==i)ans--;
    }
    cout<<ans;
    return 0;
}