//
// Created by dhy on 18-8-15.
//
#include <cstdio>
#include <time.h>
int a[1000005];
int logN[30];
int F[1000005][25];
inline int max(int a,int b){return a>b?a:b;}
inline int read(){
    int n=0,k = 1;
    char c;
    c = getchar();
    while(c>'9'||c<'0'){
        if(c=='-')k = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c = getchar();
    }
    return n*k;
}
int main(void) {
    int n, m;
    n = read();
    m = read();
    logN[0] = -1;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        logN[i] = logN[i >> 1] + 1;
        F[i][0] = a[i];
    }
    for(int j = 1;j<=21;j++)
        for(int i = 1;i+(1<<j)-1<=n;i++)
            F[i][j] = max(F[i][j-1],F[i+(1<<j-1)][j-1]);
    int x,y;
    int log = 0;
    for(int i = 1;i<=m;i++){
        x = read(),y =read();
        log = logN[y-x+1];
        printf("%d\n",max(F[x][log],F[y-(1<<log)+1][log]));
    }
}


