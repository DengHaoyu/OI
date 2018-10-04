//
// Created by dhy on 18-8-18.
//
#include <iostream>
#include <cstring>
using namespace std;
int a[201][201];
int F[201][201];
int n,m;

int main(void){
    cin>>n>>m;
    memset(a,-999, sizeof(a));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++) {
            cin >> a[i][j];
        }
    }
    int x, y;
    y = m/2+1,x = n;
    int ans = -99999099;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++){
            F[i][j] = max(max(F[i-1][j-1],F[i-1][j]),F[i-1][j+1])+a[i][j];
        }
    cout<<max(max(F[x][y],F[x][y-1]),F[x][y+1]);
    return 0;
}