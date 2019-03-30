//
// Created by dhy on 19-2-13.
//
#include <cstring>
#include <cstdio>
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXN = 1010;
int up[MAXN][MAXN],left[MAXN][MAXN],right[MAXN][MAXN];
char map[MAXN][MAXN];
char s[5];
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
int main(){
    int n = read(),m = read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%s",s);
            map[i][j] = s[0];
            up[i][j] = 1;right[i][j] = left[i][j] = j;
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(map[i][j] == 'F'&&map[i][j-1]=='F'){
                left[i][j] = left[i][j-1];
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = m-1;j>=1;j--){
            if(map[i][j] == 'F'&&map[i][j+1]=='F'){
                right[i][j] = right[i][j+1];
            }
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(i>1&&map[i][j]=='F'&&map[i-1][j]=='F'){
                right[i][j] = min(right[i-1][j],right[i][j]);
                left[i][j] = max(left[i-1][j],left[i][j]);
                up[i][j] = up[i-1][j]+1;
            }
            ans = max(ans,up[i][j]*(right[i][j]-left[i][j]+1));
        }
    }
    printf("%d",ans*3);
    return 0;
}