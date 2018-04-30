//
// Created by dhy on 18-4-30.
//
#include <iostream>
#include<vector>
#include <cmath>
using namespace std;
int absv(int a){
    if(a<0)return -a;
    return a;
}
int main(){
    vector<char> data;
    char temp;
    cin>> temp;
    while(temp!='E'){
        if(temp=='W'||temp=='L'){
            data.push_back(temp);
        }
        cin>>temp;
    }
    int a = 0;int b = 0;
    //11
    for(int i = 0;i<data.size();i++){
        if(data[i]=='W')a++;else b++;
        if((a>=11||b>=11)&&abs(a-b)>=2){
            cout<<a<<":"<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl;
    a= 0,b = 0;
    //21
    cout<<endl;
    for(int i = 0;i<data.size();i++){
        if(data[i]=='W')a++;else b++;
        if((a>=21||b>=21)&&(absv(a-b)>=2)){
            cout<<a<<":"<<b<<endl;
            a=0;
            b=0;
        }
    }
    cout<<a<<":"<<b<<endl;
    return 0;
}
