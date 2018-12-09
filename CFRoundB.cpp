//
// Created by dhy on 18-10-5.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
char map[1010][1010];
char final[1010][1010];
int mov[8][2]={
        {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}
};
bool check(int x,int y){
    for(int i = 0;i<8;i++){
        if(map[x+mov[i][0]][y+mov[i][1]]!='#')return false;
    }
    return true;
}
void mark(int x,int y){
    for(int i = 0;i<8;i++){
        final[x+mov[i][0]][y+mov[i][1]] = '#';
    }
}
int main(void){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int> v1;
    if(n%2==0){
        int sum = 0;
        int lo = pow(2,log2(n));
        v1.push_back(n);
        for(int i = 2;sum<=n/2;i++,sum+=i){
            for(int j = 1;j<=i;j++)v1.push_back(lo);
            lo/=2;
        }
        for(int i = 1;i<=(n+1)/2;i++)cout<<1<<' ';
        for(auto a = v1.begin();a!=v1.end();a++){
            cout<<*a<<' ';
        }
    }else{
        for(int i = 1;i<=(n+1)/2;i++)cout<<1<<' ';cout<<1<<' ';
        n--;
        int sum = 1;
        int lo = pow(2,log2(n));
        v1.push_back(n);
        for(int i = 2;sum<=n/2;i++,sum+=i){
            for(int j = 1;j<=i;j++)v1.push_back(lo);
            lo/=2;
        }
        for(auto a = v1.begin();a!=v1.end();a++){
            cout<<*a<<' ';
        }
    }
    return 0;
}
