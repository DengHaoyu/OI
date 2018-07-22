//
// Created by dhy on 18-7-13.
//
#include <iostream>
using namespace std;
char map[101][101];
char ans[101][101];
char *str ="yizhong";
int mv[8][2] = {{0,1},
                {0,-1},
                {1,0},
                {-1,0},
                {1,1},
                {1,-1},
                {-1,1},
                {-1,-1}};
int n;
bool dfs(int x,int y,int dir,int index){

    if(x>n||y>n||x<1||y<1){
        return false;
    }
    if(index == 6&&map[x][y] == str[index])return true;
    if(index<6&&map[x][y] == str[index]){
        return dfs(x+mv[dir][0],y+mv[dir][1],dir,index+1);
    }
    return false;
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++)
        cin>>map[i][j];

    for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++)
        ans[i][j]='*';

    for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++){
        if(map[i][j]=='y'){
            for(int d = 0;d<8;d++){
                bool found = dfs(i+mv[d][0],j+mv[d][1],d,1);
                if(found){
                    int x = i,y = j;
                    for(int i = 0;i<=6;i++){
                        ans[x][y] = str[i];
                        x+=mv[d][0];
                        y+=mv[d][1];
                    }
                }
            }
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}