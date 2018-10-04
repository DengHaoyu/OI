//
// Created by dhy on 18-8-4.
//
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int w[2001];
bool carry[2001];
int n;
int R;
bool check(int va){//can he move everything in R times with a car that carry v
    memset(carry,false, sizeof(carry));
    int t = 0;
    int v = va;
    bool trans = false;
    for(int j = 1;j<=R;j++) {
        trans = false;
        for (int i = n; i >= 1; i--) {
            if (v >= w[i] && !carry[i]) {
                carry[i] = true;
                v -= w[i];
                trans = true;
            }
        }
        v = va;
        if(trans)t++;
        if(t>R){//can't
            return false;
        }
    }
    for(int i = 1;i<=n;i++)
        if(!carry[i])return false;
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>R;
    for(int i = 1;i<=n;i++)cin>>w[i];
    sort(w+1,w+1+n);
    int l = 0,r = 0x7FFFFFF;
    int ans;
    while(l<r){
        int mid = (l+r)/2;
        if(!check(mid))ans = mid,l = mid+1;
        else ans = mid,r = mid-1;
    }
    cout<<ans;
    return  0;
}
