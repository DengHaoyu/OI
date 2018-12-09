//
// Created by dhy on 18-11-10.
//
#include <cstdio>
#include <cstdlib>
const int MAXN = 100010;
int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(c>'9'||c<'0'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar();}
    return x*f;
}
int a[MAXN];
int d[MAXN];
int main(){
    int n = read();
    for(int i = 1;i<=n;i++){
        a[i] = read();
        d[i] = a[i]-a[i-1];
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        if(d[i]>0)ans+=d[i];
    }
    printf("%d\n",ans);
    return 0;
}
