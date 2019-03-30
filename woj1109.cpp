#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int n, h[N];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&h[i]);
    int ans=0;
    for(int i=n;i>=1;i--){
        int mn=h[i];
        for(int j=i-1;j>=1;j--){
            if(h[j]>=h[i]) break;
            if(h[j]>=mn) continue;
            else mn=h[j];
            ans=max(ans,i-j+1);
        }
    }
    printf("%d\n",ans);
    return 0;
}