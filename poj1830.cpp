//
// Created by dhy on 19-3-30.
//
#include <iostream>
#include <cstring>
using namespace std;
int a[100],n,t,ans;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i<=n;i++)cin>>a[i];
        for(int i = 1;i<=n;i++){
            int j;cin>>j;
            a[i]^=j;
            a[i]|=1<<i;
        }
        int x,y;
        while(scanf("%d %d",&x,&y)!=EOF&&x&&y){
            a[y]|=1<<x;
        }
        ans = 1;
        for(int i = 1;i<=n;i++){
            for(int j=i+1;j<=n;j++)if(a[j]>a[i])swap(a[i],a[j]);
            if(a[i]==0){ans = 1<<(n-i+1);break;}//WHY?
            if(a[i]==1){ans = 0;break;}
            for(int k = n;k;k--){
                if(a[i]&(1<<k)){
                    for(int j = 1;j<=n;j++)
                        if(i!=j&&(a[j]&(1<<k)))a[j]^=a[i];
                    break;
                }

            }
        }
        if(ans==0)cout<<"Oh,it's impossible~!!"<<endl;else cout<<ans<<endl;
    }
    return 0;
}
