//
// Created by dhy on 18-10-3.
//
#include <cmath>
#include <iostream>
using namespace std;
const long long mod = (int)1e9+7;
int main(void){
    int n;
    cin>>n;
    long long ans = 0;
    for(int i = 2;i<=n-1;i++) {
        ans+=long(((int)pow(2,i)%mod)*((int)pow(2,n-i+1)%mod))%mod;
    }
    cout<<(ans+1)%mod;
    return 0;
}