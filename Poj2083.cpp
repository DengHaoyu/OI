
#include <stdio.h>
#include <string.h>
int p[8] = {1,3,9,27,81,243,729};
char map[730][730];
//n当前的图形大小，x，y图形所在的坐标
void print(int n,int x,int y){
    if(n == 0){
        map[x][y] = 'X'; //
        return;
    }
    print(n-1, x, y); //左上
    print(n-1, x+2*p[n-1], y); //右上
    print(n-1, x+p[n-1], y+p[n-1]); //中间
    print(n-1, x, y+2*p[n-1]);
    print(n-1, x+2*p[n-1],  y+2*p[n-1]);
}
int n;
int main(){
    for(int i=0; i<p[6]; i++) memset(map[i], 32, p[6]);
    print(6, 0, 0); //打表
    while(scanf("%d", &n) && n-- >= 0){
        for(int i=0; i<p[n]; i++){
            map[i][p[n]]=0;
            puts(map[i]);
            map[i][p[n]]=' ';
        }
        puts("-");
    }
    return 0;
}