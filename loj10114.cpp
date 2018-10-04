//
// Created by dhy on 18-8-10.
//
#include <iostream>
using namespace std;
int BIT[500000];
int n;
int m = 32001;
inline int lowbit(int x){return x&-x;}
void add(int x,int y){
    while(x<=m){
        BIT[x]+=y;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans = 0;
    while(x>0){
        ans+=BIT[x];
        x-=lowbit(x);
    }
    return ans;
}
struct star{int x,y;};

star stars[(int)1.5e4+5];
int ans[(int)1.5e4+5];
int main(void){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>stars[i].x>>stars[i].y;
    }
    for(int i = 1;i<=n;i++){
        int u = stars[i].x+1;
        int v = sum(u);
        add(u,1);
        ans[v]++;
    }
    for(int i = 0;i<n;i++)cout<<ans[i]<<endl;
    return 0;
}

