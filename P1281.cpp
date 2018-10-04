//
// Created by dhy on 18-8-19.
//
#include <iostream>
using namespace std;
int a[501];
int F[501][501];
int sum[502];
int m,k;
void print(int n,int M){
    int t = 0;
    if(n==0)return;
    for(int i = M;i>=1;i--){
        if(t+a[i]>F[k][m]){
            print(n-1,i);
            cout<<i+1<<' '<<M<<endl;
            return;
        }
        t+=a[i];
    }
    cout<<n<<' '<< M <<endl;
}
int main(void){
    cin>>m>>k;
    for(int i = 1;i<=k;i++)for(int j = 1;j<=m;j++)F[i][j] = 0x7ffffff;
    for(int i = 1;i<=m;i++){
        cin>>a[i];
        sum[i] = a[i]+sum[i-1];
        F[1][i] = sum[i];
    }
    int maxx = 0;
    for(int i = 2;i<=k;i++){
        for(int j = 1;j<=m;j++){
            for(int t = 1;t<j;t++){
                F[i][j] = min(F[i][j],max(F[i-1][t],sum[j]-sum[t]));
            }
        }
    }
    print(k,m);
}