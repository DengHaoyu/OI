//
// Created by dhy on 18-12-9.
//
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 25010;
int F[MAXN];
int a[MAXN];
int main(void){
    int T;
    cin>>T;
    while(T--){
        memset(F,false, sizeof(F));
        memset(a,0, sizeof(a));
        int n,ans;
        cin>>n;
        ans = n;
        for(int i = 1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        F[0] = true;
        for(int i = 1;i<=n;i++){
            if(F[a[i]]){
                ans--;
                continue;
            }
            for(int j = a[i];j<=a[n];j++)F[j] = F[j]|F[j-a[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}

