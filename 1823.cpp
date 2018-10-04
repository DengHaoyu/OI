//
// Created by dhy on 18-8-8.
//
#include <iostream>
using namespace std;
int q[500000+1],c[5000000+1] = {0};
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int l = 0;
    int temp;
    long long ans = 0;
    for(int i = 1;i<=n;i++){
        cin>>temp;
        while(l>0&&q[l]<temp)ans+=c[l--];
        if(l>0){
            if(temp==q[l]){
                ans+=c[l];
                c[l]++;
                if(l>1)ans++;
            }else{
                q[++l] = temp;
                c[l] = 1;
                ans++;
            }
        }else{
            q[++l] = temp;
            c[l] = 1;
        }
    }
    cout<<ans;
    return 0;
}
