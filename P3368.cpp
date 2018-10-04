//
// Created by dhy on 18-8-10.
//
#include <iostream>
using namespace std;
int c[500000+5];
auto lowbit = [](int x){return x&-x;};
int n;
void add(int x,int val){
    while(x<=n){
        c[x] +=val;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans = 0;
    while(x){
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    int m;
    cin>>m;
    int last = 0,temp;
    for(int i = 1;i<=n;i++){
        cin>>temp;
        add(i,temp-last);
        last = temp;
    }
    int op,x,y,k;
    for(int i = 1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }else{
            cin>>x;
            cout<<sum(x)<<endl;
        }

    }
    return 0;
}