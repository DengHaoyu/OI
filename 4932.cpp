//
// Created by dhy on 18-10-21.
//
//NOT 4932
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <vector>
#include <cstring>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){if(c=='-') f = -1;c = getchar();}
    while(c>='0'&&c<='9')x = x*10+c-'0',c = getchar();
    return x*f;
}
void print(int x){
    if(x<0)x = -x,putchar('-');
    static char s[100];//100位以内的数
    int pos = 1;
    while(x>0)s[++pos] = x%10+'0',x/=10;
    while(pos>=1)putchar(s[pos--]);
    putchar('\n');
}
const int MAXN = (int)1e6+10;
char pattern[MAXN];
int pattern_len;
int match_len;
char match[MAXN];
bool deleted[MAXN];
int kmp[MAXN];
void pre(){
    int j = 0;
    for(int i = 2;i<=pattern_len;i++){
        while(j&&pattern[i]!=pattern[j+1])j = kmp[j];
        if(pattern[i]==pattern[j+1])j++;
        kmp[i] = j;
    }
}
void work(){
    int j = 0;
    for(int i = 1;i<=match_len;i++){
        if(!deleted[i]) {
            while (j && match[i] != pattern[j + 1])j = kmp[j];
            if (match[i] == pattern[j + 1])j++;
            if (j == pattern_len) {
                int t = pattern_len;
                int index = i;
                for(;t>0;){
                    if(!deleted[index]){
                        deleted[index] = true;
                        t--;
                    }
                    index--;
                }
                j = 0;
            }
        }
    }
}
int main(void){
    scanf("%s",match+1);
    scanf("%s",pattern+1);
    match_len = strlen(match+1);
    pattern_len = strlen(pattern+1);
    pre();
    for(int i = 1;i*pattern_len<=match_len;i++) {
        work();
    }
    for(int i = 1;i<=match_len;i++){
        if(!deleted[i]){
            putchar(match[i]);
        }
    }
    return 0;
}
