
//
// Created by dhy on 18-11-24.
//
#pragma GCC optimize("Ofast")
#include <stack>
#include <cstdio>
#include <set>
using namespace std;
const int MAXN = (int)1e5+10;
const int MAXM = (int)2e5+10;
struct edge{
    int t,w,next;
}edges[MAXM<<1];
int head[MAXN];
int top = 0;
int type;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
stack<int> stk;
bool vis[MAXN<<1];
void dfs(int u){//undirected graph
    for(int &j = head[u];j;j = edges[j].next){
        int i = j;
        if(!vis[(i+1)>>1]){
            vis[(i+1)>>1] = true;
            dfs(edges[i].t);
            stk.push((i&1)?((i+1)>>1):-((i+1)>>1));
        }
    }
}
void dfs2(int u){//directed graph
    for(int &i = head[u];i;i = edges[i].next){
        int j = i;
        if(!vis[j]){
            vis[j] = true;
            dfs2(edges[j].t);
            stk.push(j);
        }
    }

}
int in[MAXN],out[MAXN];
int main(void){
    int n,m;
    type = read();
    n = read(),m = read();
    int u;
    int f,t,w;
    for(int i = 1;i<=m;i++){
        f = read(),t = read();
        u = f;
        add(f,t,1);
        out[f]++;
        in[t]++;
        if(type==1)add(t,f,1);
    }
    if(type==1){
        for(int i = 1;i<=n;i++){
            if(!(in[i]+out[i]&1)==0){
                printf("NO");
                return 0;
            }
        }
        dfs(u);
        if(stk.size()!=m){
            printf("NO");
            return 0;
        }
        printf("YES\n");
        while(!stk.empty()){
            printf("%d ",stk.top());
            stk.pop();
        }
    }else{
        for(int i = 1;i<=n;i++){
            if(in[i]!=out[i]){
                printf("NO");
                return 0;
            }
        }
        dfs2(u);
        if(stk.size()!=m){
            printf("NO");
            return 0;
        }
        printf("YES\n");
        while(!stk.empty()){
            printf("%d ",stk.top());
            stk.pop();
        }
    }

    return 0;
}

