//
// Created by dhy on 18-8-7.
//
#include <iostream>
#include <algorithm>
using namespace std;
int a[500001];
int c[500001];
int q[500001];
int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    int l = 0;
    int ans = 0;
    for(int i = 1;i<=0;i++)cin>>a[i];
    for(int i = 1;i<=n;i++){
        while(l>=0&&a[i]>q[l]){
            ans +=q[l--];
        }
        if(l){
            if(a[i]==q[l]){
                c[l]++;

            }
        }
    }
}
