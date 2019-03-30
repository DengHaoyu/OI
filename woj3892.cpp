//
// Created by dhy on 19-2-8.
//
#include <iostream>
using namespace std;
const int MAXN = (int)1e6;
bool not_prime[MAXN+10];
int primes[MAXN];
int cnt;
void prime(){
    not_prime[1] = true;
    for(int i = 2;i<=MAXN;i++){
        if(!not_prime[i]){
            primes[++cnt] = i;
        }
        for(int j = 1;j<=cnt&&i*primes[j]<=MAXN;j++){
            not_prime[i*primes[j]] = true;
            if(i%primes[j]==0)break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    prime();
    while(n!=0){
        for(int i = 1;i<=cnt;i++){
            if(!not_prime[n-primes[i]]){
                cout<<n<<" = "<<primes[i]<<" + "<<n-primes[i]<<endl;
                break;
            }
        }
        cin>>n;
    }
}
