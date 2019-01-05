//
// Created by dhy on 18-12-30.
//
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(void){
    int y,b,r;
    cin>>y>>b>>r;
    y++;
    while(--y){
        if(y+1<=b&&y+2<=r){
            cout<<y+y+1+y+2;
            return 0;
        }
    }
    return 0;
}
