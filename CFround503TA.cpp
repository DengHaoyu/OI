//
// Created by dhy on 18-8-11.
//
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n,h,a,b,k;
    ios::sync_with_stdio(false);
    cin>>n>>h>>a>>b>>k;
    int ta,fa,tb,fb;
    int ans = 0;
    for(int i = 1;i<=k;i++){
        ans = 0;
        cin>>ta>>fa>>tb>>fb;
        if(ta==tb){
            cout<<abs(fa-fb)<<endl;
            continue;
        }
        if(fa>=a&&fa<=b){
            ans+=abs(ta-tb);
            ans+=abs(fa-fb);
        }
        if(fa>b){
            ans+=fa-b;
            ans+=abs(ta-tb);
            ans+=abs(b-fb);
        }
        if(fa<a){
            ans+=a-fa;
            ans+=abs(ta-tb);
            ans+=abs(a-fb);
        }
        cout<<ans<<endl;
    }
    return 0;
}
