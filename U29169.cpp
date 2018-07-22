//
// Created by dhy on 18-7-21.
//
#include <algorithm>
#include <iostream>
using namespace std;
struct p{
    int x,y;
};
p ps[5001];
bool cmp(p p1,p p2){
    return p1.x<p2.x;
}
int n;
int main(){
    int r;
    cin>>r>>n;

    int sum=n;
    for(int i = 1;i<=n;i++)cin>>ps[i].x>>ps[i].y;
    sort(ps,ps+n+1,cmp);
    for(int i = 1;i<n;i++){
        if(ps[i+1].x-ps[i].x<=r*2&&abs(ps[i].y-ps[i+1].y)<=r*2)sum--;
    }
    cout<<sum;
    return 0;
}

