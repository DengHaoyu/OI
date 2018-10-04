//
// Created by dhy on 18-8-18.
//
#include <string>
#include <iostream>
using namespace std;
int F[20001][20001];
string a,b;
int main(void){
    ios::sync_with_stdio(false);
    cin>>a>>b;
    int n = a.size();
    int m = b.size();
//    a.insert(0,1,'#');
//    b.insert(0,1,'#');
    for(int i = 1;i<=n;i++)F[i][0] = i;
    for(int i = 1;i<=m;i++)F[0][i] = i;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++)
            if(a[i-1]==b[j-1])F[i][j] = F[i-1][j-1];
            else
            F[i][j] = min(min(F[i-1][j-1],F[i-1][j]),F[i][j-1])+1;

    cout<<F[n][m];
    return 0;
}
