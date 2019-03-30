//
// Created by dhy on 19-1-5.
//
#include <iostream>
#include <deque>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MAXN = 500010;
int x[MAXN];
int s[MAXN];
int n,d,k;
int dp[MAXN];
bool work(int g){
    int maxx = d+g;
    int minn = d-g<=0?1:d-g;
    deque<int> q;
    memset(dp,-127, sizeof(dp));
    int ans = 0;
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = i-1;j>=0;j--){
            if(x[i]-x[j]>maxx)break;
            if(x[j]+minn<=x[i]&&x[j]+maxx>=x[i]){
                dp[i] = max(dp[i], dp[j] + s[i]);
                ans = max(ans, dp[i]);
                if (ans >= k)return true;
            }
        }
    }
    return false;
}
int main(){
//    cin>>n>>d>>k;
//    for(int i = 1;i<=n;i++){
//        cin>>x[i]>>s[i];
//    }
    srand(time(0));
//    int l = 0,r = x[n];
//    while(l<r){
//        int val = l+(rand()%(r-l));
//        if(work(val))r = val;
//        else l = val+1;
//    }
//    cout<<l;
    return 0;
};
 Created by dhy on 19-1-12.


 Created by dhy on 19-1-12.
