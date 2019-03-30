//
// Created by dhy on 19-2-19.
//

#include <cstdlib>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
const int MAXN = 10010;
struct edge{
    int t,w,next;
}edges[MAXN<<2];
int head[MAXN];
int top;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int dfn[MAXN],low[MAXN],dfn_cnt;
int cut[MAXN];
void tarjan(int x,int fa){
    dfn[x] = low[x] = ++dfn_cnt;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(!dfn[t]){
            tarjan(t,x);
            low[x] = min(low[x],low[t]);
            if(dfn[x]<=low[t]){
                cut[x]++;
            }
        }else if(t!=fa&&dfn[x]>dfn[t]){
            low[x] = min(low[x],dfn[t]);
        }
    }
}
int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF){
        if(!n&&!m)break;
        int f,t;
        memset(dfn,0,sizeof(dfn));dfn_cnt = 0;
        memset(head,0,sizeof(head));top = 0;
        memset(cut,0, sizeof(cut));
        memset(low,0, sizeof(low));
        for(int i = 1;i<=m;i++){
            scanf("%d %d",&f,&t);
            f++,t++;
            add(f,t,1);
            add(t,f,1);
        }
        int block = 0;
        for(int i = 1;i<=n;i++){
            if(!dfn[i]){tarjan(i,i);block++;cut[i]--;}
        }
        int ans = -1;

        for(int i = 1;i<=n;i++){
            ans = max(ans,cut[i]);

        }
        printf("%d\n",ans+block);
    }
    return 0;
}