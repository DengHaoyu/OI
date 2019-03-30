//
// Created by dhy on 1
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1010;
int map[MAXN][MAXN];
int sum[MAXN][MAXN];
int k[MAXN];
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
int main(){
    int a = read(),b = read(),n = read();
    for(int i = 1;i<=a;i++){
        for(int j = 1;j<=b;j++)map[i][j] = read();
    }
    for(int j = 1;j<=b;j++){
        for(int i = 1;i<=a;i++)sum[i][j] = sum[i][j-1]+map[i][j];
    }
    for(int i = n;i<=a;i++){
        for(int j = 1;j<=b;j++)k[j] = sum[i][j]-sum[i][j-n-1];
        
    }

    return 0;
}
