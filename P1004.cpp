//
// Created by dhy on 18-8-18.
//
#include <iostream>
using namespace std;
int F[10][10][10][10];
int map[10][10];
int main(void){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    while(!(a==0&&b==0&&c==0)){
        map[a][b] = c;
        cin>>a>>b>>c;
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                for(int l = 1;l<=n;l++){
                    int v1 = max(F[i-1][j][k-1][l],F[i][j-1][k][l-1]);
                    int v2 = max(F[i-1][j][k][l-1],F[i][j-1][k-1][l]);
                    F[i][j][k][l] = max(v1,v2)+map[i][j];
                    if(i!=k&&j!=l)F[i][j][k][l]+=map[k][l];
                }
            }
        }
    }
    cout<<F[n][n][n][n];
    return 0;
}
