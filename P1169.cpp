//
// Created by dhy on 19-1-13.
//
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 2010;
int map[MAXN][MAXN];
int up[MAXN][MAXN];
int lft[MAXN][MAXN];
int rght[MAXN][MAXN];
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
int main(){
    int n,m;
    memset(map,-1,sizeof(map));
    cin>>n>>m;
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            map[i][j] = read();
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            lft[i][j] = rght[i][j] = j;
            up[i][j] = 1;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 2;j<=m;j++){
            if(map[i][j]!=map[i][j-1]){
                lft[i][j] = lft[i][j-1];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = m-1;j>=1;j--){
            if(map[i][j]!=map[i][j+1]){
                rght[i][j] = rght[i][j+1];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++) {
            if (i > 1 && map[i - 1][j] != map[i][j]) {
                lft[i][j] = max(lft[i][j], lft[i - 1][j]);
                rght[i][j] = min(rght[i][j], rght[i - 1][j]);
                up[i][j] = up[i - 1][j] + 1;
            }

            int a = rght[i][j] - lft[i][j]+1;
            int b = min(a,up[i][j]);
            ans1 = max(ans1,b*b);
            ans2 = max(ans2,up[i][j]*a);
        }
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}
