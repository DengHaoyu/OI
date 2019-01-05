//
// Created by dhy on 18-12-15.
//
#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=7)cout<<1<<endl;
        else cout<<n/7+1<<endl;
    }
    return 0;
}