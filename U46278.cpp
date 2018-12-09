//
// Created by dhy on 18-10-28.
//
#include <iostream>
using namespace std;
int main(){
    int m,k;
    cin>>m>>k;
    int t = 1;
    for(int i = 1;i<=9000000;i++){
        t*=k;
        t%=m;
        if(t==1){
            cout<<i;
            return 0;
        }
    }

    cout<<"Let's go Blue Jays!"<<endl;
    return 0;
}
