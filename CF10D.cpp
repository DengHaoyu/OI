//
// Created by dhy on 18-8-17.
//
#include <stdio.h>
inline int read(){
    int n = 0,f = 1;
    char c = getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c = getchar();
    }
    return n*f;
}
int str[505];
int a[505];
int b[505];
int tot = 0;
int n,m;
int main(){

}