//
// Created by dhy on 18-12-23.
//

#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = (int)1e6+1;
int F[MAXN][21];
int logN[MAXN];
int n,k;
int a[MAXN];
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}

void initlogN(){
    logN[0] = -1;
    for(int i = 1;i<=n;i++)logN[i] = logN[i>>1]+1,F[i][0] = a[i];
}
inline int d_min(int x,int y){return x>y?y:x;}
inline int d_max(int x,int y){return x>y?x:y;}
void initST(){
    for(int i = 1;i<=20;i++){
        for(int j = 1;j+(1<<i)-1<=n;j++){
            F[j][i] = d_max(F[j][i-1],F[j+(1<<i-1)][i-1]);
        }
    }
}

void initMin(){
    for(int i = 1;i<=20;i++){
        for(int j = 1;j+(1<<i)-1<=n;j++){
            F[j][i] = d_min(F[j][i-1],F[j+(1<<i-1)][i-1]);
        }
    }
}
int queryMax(int x,int y){
    int l = logN[y-x+1];
    return d_max(F[x][l],F[y-(1<<l)+1][l]);
}
int queryMin(int x,int y){
    int l = logN[y-x+1];
    return d_min(F[x][l],F[y-(1<<l)+1][l]);
}
int main() {
    n = read(),k = read();
    for(int i = 1;i<=n;i++)a[i] = read();
    initlogN(),initMin();
    for(int i = 1;i<=n-k+1;i++)printf("%d ",queryMin(i,i+k-1));
    printf("\n");
    initST();
    for(int i = 1;i<=n-k+1;i++)printf("%d ",queryMax(i,i+k-1));
    return 0;
}