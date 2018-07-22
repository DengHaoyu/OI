//
// Created by dhy on 18-7-22.
//
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int ans[1001];
int save[1001];
void cacu(){
    memset(save,0, sizeof(save));
    for(int i = 1;i<=500;i++)
        for(int j = 1;j<=500;j++)
            save[i+j-1] = ans[i]*ans[j];
    for(int i = 1;i<=500;i++){
        save[i+1] = save[i]/10;
        save[i]%=10;
    }
    memcpy(ans,save,sizeof(save));
}
void twice(){
    memset(save,0, sizeof(save));
    for(int i = 1;i<=500;i++)save[i] = ans[i]*2;
    for(int i = 1;i<=500;i++){
        save[i+1] = save[i]/10;
        save[i]%=10;
    }
    memcpy(ans,save,sizeof(save));
}
int main(){
    int p;
    cin>>p;
    cout<<ceil(p*log10(2))<<endl;
    memset(ans,0,sizeof(ans));
    ans[1] = 2;
    while(p!=0){
        if(p&1!=0)twice();
        p = p>>1;
        cacu();
    }
    for(int i = 500;i>=1;i--)cout<<ans[i];
    return 0;
}
