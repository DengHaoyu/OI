//
// Created by dhy on 18-9-7.
//
#include <iostream>
using namespace std;
long long min(long long a,long long b){return a>b?b:a;}
long long max(long long a,long long b){return a<b?b:a;}
inline long long min_step(long long x,long long y){
    return max(x,y);
}
inline long long min_step_diagonalMove(long long x,long long y){
    return min(x,y);
}
//long long mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int main(void){
    ios::sync_with_stdio(false);
    long long q;
    cin>>q;
    long long x,y,k;
    for(long long i = 1;i<=q;i++){
        cin>>x>>y>>k;
        if(min_step(x,y)>k){
            cout<<-1<<endl;
            continue;
        }
        k-=1;
        long long ans = min_step_diagonalMove(x-1,y);
        k-=min_step(x-1,y);
        ans+=k;
        cout<<ans<<endl;
    }
    return 0;
}
