//
// Created by dhy on 18-8-10.
//
#include <iostream>
using namespace std;
int c[500005];
int n;
inline int lowbit(int x){return x&-x;}
inline void add(int x,int y){
    while(x<=n){
        c[x]+=y;
        x+=lowbit(x);
    }
}
inline int sum(int x){
    int ans = 0;
    while(x>=1){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    int x,y,z;
    for(int i = 1;i<=n;i++){
        cin>>x;
        add(i,x);
    }
    for(int i = 1;i<=m;i++){
        cin>>x>>y>>z;
        if(x==1){
            add(y,z);
        }else{
            cout<<sum(z)-sum(y-1)<<endl;
        }
    }
    return 0;
}
