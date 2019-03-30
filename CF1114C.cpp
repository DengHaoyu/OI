//
// Created by dhy on 19-2-10.
//
#include <iostream>
using namespace std;
long long factor_k[(int)1e7];
long long factor_cnt[(int)1e7];
int fa_cnt;
int main(){
    ios::sync_with_stdio(false);
    unsigned long long n,k;cin>>n>>k;
    for(int i = 2;i*i<=k;i++){
        if(k%i==0){
            factor_k[++fa_cnt] = i;factor_cnt[fa_cnt] = 0;
            while(k%i==0)k/=i,factor_cnt[fa_cnt]++;
        }
    }
    if(k!=1)factor_k[++fa_cnt] = k,factor_cnt[fa_cnt] = 1;
    long long ans = 0x7f3f7f7f7f7f7f7f;
    for(int i = 1;i<=fa_cnt;i++){
        long long t = 0;long long curr = n;
        while(curr){
            curr/=factor_k[i];
            t+=curr;
        }
        t/=factor_cnt[i];
        ans = min(ans,t);
    }
    cout<<ans;
    return 0;
}