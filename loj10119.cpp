//
// Created by dhy on 18-8-11.
//
#include <iostream>
#include <algorithm>
using namespace std;
int log2[(int)1e6+5];
int F[(int)1e6+5][25];
int a[(int)1e6+5];
int logN = 20;
int main(){
    int n,m;
    ios::sync_with_stdio(false);
    cin>>n>>m;
    log2[0] = -1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        F[i][0] = a[i];
        log2[i] = log2[i>>1]+1;
    }
    for(int i = 1;i<=logN;i++){
        for(int j = 1;j+(1<<i)-1<=n;j++){
            F[j][i] = max(F[j][i-1],F[j+(1<<i-1)][i-1]);
        }
    }
    int l,r;
    int s;
    for(int i = 1;i<=m;i++){
        cin>>l>>r;
        s = log2[r-l+1];
        cout<<max(F[l][s],F[r-(1<<s)+1][s])<<endl;
    }
}