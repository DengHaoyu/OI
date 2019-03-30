//
// Created by dhy on 19-2-10.
//
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXN = (int)2e5+10;
int a[MAXN];pair<int,int>b[MAXN];
bool match[MAXN];
int as[MAXN];int cnt;
int main(){
    int n = read(),m = read(),k = read();
    for(int i = 1;i<=n;i++)a[i] = read(),b[i].first = a[i],b[i].second = i;
    sort(b+1,b+1+n);
    long long ans = 0;
    vector<int> ind(m*k);
    for(int i = n;i>=n-m*k+1;i--){
        match[b[i].second] = true;
        ans+=b[i].first;
    }
    printf("%lld\n",ans);
    int curr = 0;
    for(int i = 1;i<=n;i++){
        if(match[i])curr++;
        if(curr>=m)as[++cnt] = i,curr=0;
    }
    for(int i = 1;i<k;i++)printf("%d ",as[i]);
    return 0;
}