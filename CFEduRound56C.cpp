//
// Created by dhy on 18-12-15.
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
const int MAXN = (int)2e6+10;
long long a[MAXN];
long long ans[MAXN];
int main(){
    int n;
    cin>>n;
    int mid = n/2;
    for(int i = 1;i<=n>>1;i++)cin>>a[i];
    ans[mid] = a[mid]>>1;
    ans[mid+1] = a[mid]-ans[mid];
    for(int i = mid-1,j=mid+2;i>=1&&j<=n;i--,j++){
        ans[j] = ans[j-1];
        long long diff = a[i]-ans[j];
        if(diff>ans[i+1])ans[i] = ans[i+1],ans[j] = a[i]-ans[i];
        else ans[i] = diff;
    }
    for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}