//
// Created by dhy on 18-8-16.
//
#include <stdio.h>
inline int max(int a,int b){return a>b?a:b;}
inline int read(){
    int c,n = 0,f = 1;
    c = getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c = getchar();
    }
    return n*f;
}
inline void write(int n){
    if(n==0){
        putchar('0');
        putchar('\n');
        return;
    }
    while(n>0){
        putchar(n%10+'0');
        n/=10;
    }
}
struct node{
    int head,tail;
};
int temp[101];
node nodes[401];
int F[401][401] = {0};
int main(void){
    int n = read();
    for(int i = 1;i<=n;i++){
        temp[i] = read();
        temp[i+n] = temp[i];
    }

    for(int i = n*2;i>0;i--){
        for(int j = i+1;j<=i+n;j++){
            for(int k = i;k<j;k++)
                F[i][j] = max(F[i][j],F[i][k]+F[k+1][j]+temp[i]*temp[k+1]*temp[j+1]);
        }
    }

    int ans = 0;
    for(int i = 1;i<=n;i++)ans = max(ans,F[i][i+n-1]);
    printf("%d",ans);
    return 0;
}