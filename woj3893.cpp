//
// Created by dhy on 19-2-8.
//
#include <cstring>
#include<iostream>
using namespace std;
const int MAXN = (int)1e6+32;
int col[MAXN + 10];
int color;
bool not_prime[MAXN+10];
int primes[MAXN];
int cnt;
void prime(){
    not_prime[1] = true;
    for(int i = 2;i<MAXN-9;i++){
        if(!not_prime[i]){
            primes[++cnt] = i;
        }
        for(int j = 1;j<=cnt&&i*primes[j]<MAXN-9;j++){
            not_prime[i*primes[j]] = true;
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
    int n ;cin>>n;
    prime();
    if(n<3){
        if(n==1)cout<<1<<endl;
        if(n==2)cout<<1<<endl<<1<<' '<<1;
        return 0;
    }
    cout<<2<<endl;
    for(int i = 2;i<=n+1;i++)if(not_prime[i])cout<<1<<' ';else cout<<2<<' ';
    return 0;
}