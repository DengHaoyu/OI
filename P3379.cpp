//
// Created by dhy on 18-8-15.
//
#include <cstdio>

using namespace std;
struct node{int t,next;}tree[2*500001];
int head[500001];
int F[500000][23];
int deepth[500001];
int tot = 0;
int log2[5000001];
inline int read(){
    int c,n = 0,f = 1;
    c = getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f = -1;
        c = getchar();
    }
    while(c>='0'&&c<='9'){
        n*=10;
        n+=c-'0';
        c = getchar();
    }
    return n*f;
}
inline void put(int x)
{    if(x==0){putchar('0');putchar('\n');return;}
    int num =0;char c[25];
    while(x) c[++num] =(x%10)+48,x/=10;
    while(num) putchar(c[num--]);
    putchar('\n');
}

void sswap(int &a,int&b){
    int  c;
    c = a;
    a = b;
    b = c;
}
void add(int from,int to){
    tree[++tot].next = head[from];
    tree[tot].t = to;
    head[from] = tot;
}
void dfs(int curr,int fa){
    deepth[curr] = deepth[fa]+1;
    F[curr][0] = fa;
    for(int i = 1;(1<<i)<=deepth[curr];i++)
        F[curr][i] = F[F[curr][i-1]][i-1];
    for(int i = head[curr];i!=0;i = tree[i].next){
        if(tree[i].t!=fa)
            dfs(tree[i].t,curr);
    }
}
int LCA(int x,int y){
    if(deepth[x]<deepth[y])sswap(x,y);
    while(deepth[x]>deepth[y]){
        x = F[x][log2[deepth[x]-deepth[y]]-1];
    }
    if(x==y)return x;
    for(int i = log2[deepth[x]];i>=0;i--){
        if(F[x][i]!=F[y][i]){
            x = F[x][i];
            y = F[y][i];
        }
    }
    return F[x][0];
}
int main(void){
    int n,m,s;
    n = read();
    m = read();
    s = read();
    int f,t;
    for(int i = 1;i<=n-1;i++){
        f = read();
        t = read();
        add(f,t);
        add(t,f);
    }
    for(int i = 1;i<=n;i++){
        log2[i]=log2[i-1]+(1<<log2[i-1]==i);
    }
    dfs(s,0);
    for(int i = 1;i<=m;i++){
        f = read();
        t = read();
        put(LCA(f,t));
    }
    return 0;
}