//
// Created by dhy on 18-9-7.
//
#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    unsigned long long n,k;
    cin>>n>>k;
    if(n>=k){
        cout<<1<<endl;
    }else{
        if(k%n==0){
            cout<<k/n;
        }else{
            cout<<k/n+1;
        }
    }
    return 0;
}
