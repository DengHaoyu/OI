//
// Created by dhy on 18-8-8.
//
#include <iostream>
#include <algorithm>
using namespace std;
int a[10000];
int sa[1000],sb[1000],sc[1000],sd[1000];
int main(void){
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int A = 0,B = 0,C = 0,D = 0;
    for(int i = 1;i<=n;i++){
        if(a[i]>=90) {
            sa[++A] = a[i];
            continue;
        }
        if(a[i]>=80){
            sb[++B] = a[i];
            continue;
        }
        if(a[i]>=70){
            sc[++C] = a[i];
            continue;
        }
        sd[++D] = a[i];
    }
    int maxx = max(max(A,B),max(C,D));
    int *max_array;
    if(maxx==A)max_array = sa;
    if(maxx==B)max_array = sb;
    if(maxx==C)max_array = sc;
    if(maxx==D)max_array = sd;
    for(int i = 1;i<=maxx;i++){
        cout<<max_array[i]<<' ';
    }

    return 0;
}

