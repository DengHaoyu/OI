//
// Created by dhy on 18-8-29.
//
#include <algorithm>
#include <iostream>
using namespace std;
struct cow{
    int minSPF,maxSPF;
    bool operator<(cow c2){
        return minSPF>c2.minSPF;
    }
};
struct cream{
    int count,SPF;
    bool operator<(cream c2){
        return SPF<c2.SPF;
    }
};
cow cows[2500];
cream creams[2500];
int main(void){
    int C,L;
    ios::sync_with_stdio(false);
    cin>>C>>L;
    for(int i = 1;i<=C;i++)cin>>cows[i].minSPF>>cows[i].maxSPF;
    for(int i = 1;i<=L;i++)cin>>creams[i].SPF>>creams[i].count;
    sort(cows+1,cows+C+1);
    sort(creams+1,creams+L+1);
    int ans = 0;
    for(int i = 1;i<=C;i++){
        int p = 1,pos = 0;
        while(p!=0){
            if(p+pos<=L&&cows[i].minSPF<=creams[p+pos].SPF&&cows[i].maxSPF>=creams[p+pos].SPF&&creams[p+pos].count>0){
                pos+=p;
                p*=2;
            }else{
                p/=2;
            }
        }
        if(pos!=0) {
            creams[pos].count--;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}