//
// Created by dhy on 19-1-5.
//
#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
const int MAXN = 500010;
int x[MAXN];
int s[MAXN];
int n,d,k;
long long dp[MAXN];
bool work(int g){
    int maxx = d+g;
    int minn = d-g<=0?1:d-g;
    deque<int> q;
    memset(dp,0x8c, sizeof(dp));
    int cur = 0;
    dp[0] = 0;
    for(int i = 1;i<=n;i++){
        for(;cur<i&&x[cur]+minn<=x[i];cur++){
            if(q.empty())q.push_back(cur);
            else {
                if(dp[cur] == dp[MAXN-5])continue;
                while (!q.empty()&&dp[q.back()]<=dp[cur])q.pop_back();
                q.push_back(cur);
            }
        }
        while (!q.empty()&&x[q.front()]+maxx<x[i])q.pop_front();
        if(!q.empty())dp[i] = dp[q.front()]+s[i];
        else dp[i] = dp[MAXN-6];
        if(dp[i]>=k)return true;
    }
    return false;
}
int main(){
    cin>>n>>d>>k;
    for(int i = 1;i<=n;i++){
        cin>>x[i]>>s[i];
    }
    int l = 0,r = x[n];
    while(l<r){
        int mid = l+r>>1;
        if(work(mid))r = mid;
        else l = mid+1;
    }
    cout<<l;
    return 0;
};
