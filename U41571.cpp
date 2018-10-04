//
// Created by dhy on 18-10-4.
//
#include <iostream>
using namespace std;
const int MAXN = (int)1e7+10;
inline int lowbit(int x){
    return x&-x;
}
int s[MAXN];
int n;
inline int update(int a,int val){
    int l = a;
    while(l<=n){
        s[l]+=val;
        l+=lowbit(l);
    }
}
inline int query(int a){
    int ans = 0;
    while(a>=1){
        ans+=s[a];
        a-=lowbit(a);
    }
    return ans;
}
int main(void){
    ios::sync_with_stdio(false);
    int m;
    cin>>n>>m;
    int o,x,y;
    for(int i = 1;i<=m;i++){
        cin>>o;
        if(o==0){
            cin>>x>>y;
            update(x,1);
            update(y+1,-1);
        }else{
            cin>>x;
            cout<<query(x);
        }
    }
    return 0;
}


