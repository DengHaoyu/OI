//
// Created by dhy on 19-2-10.
//
#include <iostream>
using namespace std;
int main(){
    int x,y,z,a,b,c;cin>>x>>y>>z>>a>>b>>c;
    bool flag = true;
    if(a<x){
        flag = false;
    }else{
        a-=x;
    }
    if(a+b<y){
        flag = false;
    }else{
        if(a<y)y-=a,a = 0;else a-=y,y = 0;
        b-=y;
    }
    if(a+b+c<z){
        flag = false;
    }
    if(flag)cout<<"YES";else cout<<"NO";
    return 0;
}
