//
// Created by dhy on 18-8-30.
//
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
struct segment{
    int l,r;

};
bool operator<(segment s1,segment s2){
    return s1.r<s2.r;
}
segment sgmts[1001];
int main(void){
//    int a,b;
//    int ind = 1;
//    ios::sync_with_stdio(false);
//    cin>>a>>b;
//    int t1,t2;
//    bool vaild = true;
//    while(!(a==0&&b==0)){
//        for(int i = 1;i<=a;i++){
//            cin>>t1>>t2;
//            if(t2>b){
//                vaild = false;
//                break;
//            }
//            double w = sqrt((b*b)-t2*t2);
//            sgmts[i].l = ((double)t1)-w;
//            sgmts[i].r = ((double)t1)+w;
//        }
//        if(!vaild){
//            cout<<"Case 1: -1"<<endl;
//            continue;
//        }
//        int ans = 0;
//        double pos = -99999999.0;
//        sort(sgmts+1,sgmts+1+a);
//        for(int i = 1;i<=a;i++){
//            if(sgmts[i].l>pos){
//                ans++;
//                pos = sgmts[i].r;
//            }
//        }
//        cout<<"Case "<<ind<<": "<<ans<<endl;
//        ind++;
//        cin>>a>>b;
//    }
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>sgmts[i].l>>sgmts[i].r;
    }
    sort(sgmts+1,sgmts+1+n);
    int  ans = 0;
    int pos = -9999;
    for(int i = 1;i<=n;i++){
        if(sgmts[i].l>=pos){
            ans++;
            pos = sgmts[i].r;
        }
    }
    cout<<ans;
    return 0;
}