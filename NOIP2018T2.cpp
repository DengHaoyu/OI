//
// Created by dhy on 18-11-10.
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(c>'9'||c<'0'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar();}
    return x*f;
}
const int MAXVAL = 25000;
int a[MAXVAL];
bool exist[MAXVAL];
int main(){
    int T = read();
    while(T--){
        memset(a,0,sizeof(a));
        memset(exist,false, sizeof(exist));
        int n = read();
        for(int i = 1;i<=n;i++){
            a[i] = read();
            for(int j = 1;j*a[i]<=MAXVAL;j++)exist[j*a[i]] = true;
        }
        sort(a+1,a+1+n);
        int ans = n;
        for(int i = 2;i<=n;i++){
            bool flag = false;
            for(int j = 1;j<i&&flag==false;j++){
                for(int k = 1;k*a[j]<=a[i];k++){
                    if(exist[a[i]-k*a[j]]){
                        ans--;
                        flag = true;
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

