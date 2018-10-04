//
// Created by dhy on 18-8-11.
//
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
    int a[1001];
    int cnt[1001];
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    int p;
    for(int i = 1;i<=n;i++){
        memset(cnt,0, sizeof(cnt));
        p = i;
        while(cnt[p]!=2){
            cnt[p]++;
            p = a[p];
        }
        cout<<p<<' ';
    }
    return 0;
}
