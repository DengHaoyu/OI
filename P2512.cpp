//
// Created by dhy on 18-9-1.
//
#include <cmath>
#include <iostream>
using namespace std;
int candies[(int)2e6+1];
int main(void){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        cin>>candies[i];
        candies[i+n] = candies[i];
        sum+=candies[i];
    }
    sum/=n;
    for(int i = 1;i<=n+n;i++)candies[i]-=sum;
    int cos = 999999;
    for(int l = 1;l<=n;l++){
        int co = 0;
        for(int i = l;i<l+n;i++){
            candies[i+1]+=candies[i];
            co+=abs(candies[i]);
        }
        co+=candies[l+n];
        cos = min(co,cos);
    }
    cout<<cos;
    return 0;
}
