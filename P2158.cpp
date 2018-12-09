//
// Created by dhy on 18-11-10.
//
#include <cstring>
#include <cstdio>
#include <queue>
#include <fstream>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-') f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
inline int gcd(int a,int b){return b==0?a:(gcd(b,a%b));}
int get(int x){
    int ans = 0;
    for(int i = 2;i<=x;i++)
        for(int j = 2;j<=x;j++)
            if(gcd(i,j)==1)ans++;
            return ans;
}
int main(){
    ofstream out("data");
    for(int i = 1;i<=40000;i++){
        out<<get(i)<<',';
    }
    return 0;
}