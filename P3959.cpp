#include <cstdio>
#include <stack>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int INF = 999999999;
int n,m,q;
int read(){int x = 0,f = 1;static char c = getchar();while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }return x*f;}
const int MAXN = 13;
int map[MAXN][MAXN];
long long s;
struct node{
    int d[MAXN];int dep[MAXN];
    node(){
        for(int i = 1;i<=n;i++)d[i] = i,dep[i] = 0;
    }
    node(const node &n2){
        memcpy(d,n2.d,sizeof(d));memset(dep,0,sizeof(dep));
        swap(d[rand()%n+1],d[rand()%n+1]);
    }
    int dis(){
        dep[d[1]] = 1;
        int ans = 0;
        for(int i = 2;i<=n;i++){
            int temp = INF;
            for(int j = 1;j<i;j++){
                if(map[d[j]][d[i]]!=0x3f3f3f3f&&map[d[j]][d[i]]*dep[d[j]]<temp){
                    temp = map[d[j]][d[i]]*dep[d[j]];dep[d[i]] = dep[d[j]]+1;
                }
            }
            if(temp == INF){
                return temp;
            }else ans+=temp;
        }
        return ans;
    }
};
const double T = 1926;
const double delta = 0.998;
int SA(){
    node current_ans;
    double curr_T = T;
    while(curr_T>0.01){
        node new_ans(current_ans);
        int del = new_ans.dis()-current_ans.dis();
        if(del<=0){
            current_ans = new_ans;
        }else if(exp(-del/curr_T)*RAND_MAX>rand()){
            current_ans = new_ans;
        }
        curr_T*=delta;
    }
    return current_ans.dis();
}
int main(){
    n = read();
    m = read();
    int f,t,w;

    memset(map,0x3f,sizeof(map));
    for(int i = 1;i<=m;i++){
        f = read(),t = read(),w = read();
        map[f][t] = map[t][f] = min(map[f][t],w);
    }
    int ans = 999999999;
    ans = min(ans,SA());ans = min(ans,SA());ans = min(ans,SA());
    ans = min(ans,SA());ans = min(ans,SA());ans = min(ans,SA());
    printf("%d",ans);
    return 0;
}

