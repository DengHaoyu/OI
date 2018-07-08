//
// Created by dhy on 18-7-7.
//
#include <iostream>
#include<algorithm>
using namespace std;
struct provider{
    int price;
    int amount;
};
bool cmp(provider p1,provider p2){
    return p1.price<p2.price;
}
int main(){
    int N,M;
    cin>>N>>M;
    provider providers[M+1];
//    provider *providers = new provider[M+1]();
    for(int i = 1;i<=M;i++){
        cin>>providers[i].price;
        cin>>providers[i].amount;
    }
    long long sum = 0;
    sort(providers+1,providers+M+1,cmp);
    for(int i = 1;i<=M;i++){
        if(N<=0) break;
        if(N>=providers[i].amount){
            sum+=providers[i].amount*providers[i].price;
            N-=providers[i].amount;
        }else{
            sum+=N*providers[i].price;
            N = 0;
        }
    }
    cout<<sum;
}
