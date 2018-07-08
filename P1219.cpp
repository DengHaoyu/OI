//
// Created by dhy on 18-7-7.
//
#include <iostream>
#define not_allowed 2

using namespace std;
int N;
int map[14][14];
const int chess = 1;
void dfs(int ind){
    if(ind>N)return;
    for(int i = ind;i<=N;i++){
        if(map[ind][i]!= not_allowed&&map[ind][i]!=chess){//can put
            for(int j = 1;j<=N;j++)map[i][j] = not_allowed;
            for(int j = 1;j<=N;j++)
        }
    }
}
int main(){
    cin>>N;

}