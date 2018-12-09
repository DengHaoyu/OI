//
// Created by dhy on 18-11-4.
//
#include <cstring>
#include <cstring>
#include <iostream>
using namespace std;
int len;
int mod = 26;
char str[601];
int ans[10001];
void mul(int n){
    for(int i = 1;i<=1000;i++){
        ans[i]*=n;
    }
    for(int i = 2;i<=1000;i++){
        while(ans[i-1]>=10){
            ans[i]++;
            ans[i-1]-=10;
        }
    }
}
int main(void){
    int n,R;
    cin>>n>>R;
    R%=mod;
    ans[1] = 1;
    mul(980);
    mul(100);
    while(n--){
        cin>>str+1;
//        memset(ans,0, sizeof(ans));
//        ans[1] = 1;
        unsigned long long res = 1;
        len = strlen(str+1);
        for(int i = 1;i<=len;i++){
            cout<<(char)(((str[i]-'A'+R)%mod)+'A');
            str[i] = (str[i]-'A'+R)%mod+'A';
            res*=str[i];
        }
        cout<<endl;
        cout<<res<<endl;
    }
    return 0;

}
