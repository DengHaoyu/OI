//
// Created by dhy on 19-2-23.
//
#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define  mp(a,b) make_pair(a,b)
typedef pair<long long ,int > plii;
int mv[4][2] = {{0,-1},{1,0},{-1,0},{0,1}};
int matrix[4][4];
map<long long,bool> exist;
vector<plii > states;
long long start,target = 123804765;
queue<plii > q;
long long transfer(long long s,int d){
    int x0,y0,tx,ty;
    long long tar = 0;
    for(int i = 3;i>=1;i--){
        for(int j = 3;j>=1;j--){
            if(s%10==0)x0 = i,y0 = j;
            matrix[i][j] = s%10;
            s/=10ll;
        }
    }
    tx = x0+mv[d][0],ty = y0+mv[d][1];
    if(tx<1||tx>3||ty<1||ty>3)return 0;
    swap(matrix[x0][y0],matrix[tx][ty]);
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            tar = tar*10+matrix[i][j];
        }
    }
    return tar;
}
int bfs(){
    exist[start] = true;
    q.push(mp(start,0));
    while(!q.empty()){
        plii top = q.front();q.pop();
        if(top.first==target){
            return top.second;
        }
        for(int i = 0;i<4;i++){
            long long t = transfer(top.first,i);
            if(t==0)continue;
            if(exist.count(t)!=0)continue;
            exist[t] = true;
            q.push(mp(t,top.second+1));
        }
    }
    return -1;
}
int main(){
    cin>>start;
    int p = bfs();
    if(p==-1){
        cout<<"NO solution!";return 0;
    }else{
        cout<<p;
    }
    return 0;
}
