//
// Created by dhy on 18-10-5.
//
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = (int )1e5+10;
struct customer{
    int start,off;
    bool operator<(const customer& c)const{
        return start<c.start;
    }
}customers[MAXN];
int n,L,a;
int main(void){
    ios::sync_with_stdio(false);
    cin>>n>>L>>a;
    int b,c;
    for(int i = 1;i<=n;i++){
        cin>>b>>c;
        customers[i].start = b;
        customers[i].off = b+c;
    }
    int ans = 0;
    sort(customers+1,customers+n+1);
    for(int i = 0;i<n;i++){
        if(customers[i+1].start-customers[i].off>=a){
            ans+=(customers[i+1].start-customers[i].off)/a;
        }
    }
    ans+=(L-customers[n].off)/a;
    cout<<ans;
    return 0;
}
