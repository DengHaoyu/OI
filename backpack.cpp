//
// Created by dhy on 18-12-23.
//

#include <cstring>
#include <cstdio>
#include <deque>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXN = 1e6;
const int MAXM = 1e6;
int F[MAXM];
int V[MAXN];
int C[MAXN];
int W[MAXN];
inline int cal(int i,int u,int k){return F[u+k*V[i]]-k*W[i];}
int n,m;
int main() {
    n = read(),m = read();
    memset(F,0xcf, sizeof(F));//-INF
    F[0] = 0;
    for(int i = 1;i<=n;i++){
        V[i] = read(),W[i] = read(),C[i] =read();
        for(int u = 0;u<V[i];u++){
            deque<int> q;
            int maxp = (m-u)/V[i];
            for(int k = maxp-1;k>=max(maxp-C[i],0);k--){
                while(!q.empty()&&cal(i,u,q.back())<=cal(i,u,k))q.pop_back();
                q.push_back(k);
            }
            for(int p = maxp;p>=0;p--){
                while(!q.empty()&&q.front()>p-1)q.pop_front();
                if(!q.empty())F[u+p*V[i]] = max(F[u+p*V[i]],cal(i,u,q.front())+p*W[i]);
                if(p-C[i]-1>=0){
                    while(!q.empty()&&cal(i,u,q.back())<=cal(i,u,p-C[i]-1))q.pop_back();
                    q.push_back(p - C[i] - 1);
                }
            }

        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)ans = max(ans,F[i]);
    printf("%d ",ans);
    return 0;
}
