//
// Created by dhy on 18-12-2.
//
#include <cstdio>
const int MAXN = 30010;
struct edge{
    int t,w,next;
}edges[MAXN<<1];
int head[MAXN];
int top;
const int INF = 999999999;
inline int max(int a,int b){return a>b?a:b;}
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
int w[MAXN],wei[MAXN];
int dep[MAXN],id[MAXN],father[MAXN],track[MAXN];
int son[MAXN],size[MAXN];
int root;
int n;
int cnt;
void dfs1(int x,int fa){
    father[x] = fa;
    dep[x] = dep[fa]+1;
    size[x] = 1;
    int maxx = 0;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(t!=fa){
            dfs1(t,x);
            size[x]+=size[t];
            if(maxx<size[t]){
                maxx = size[t];
                son[x] = t;
            }
        }
    }
}
void dfs2(int x,int tp){
    track[x] = tp;
    id[x] = ++cnt;
    wei[id[x]] = w[x];
    if(!son[x])return;
    dfs2(son[x],tp);
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(t!=son[x]&&t!=father[x]){
            dfs2(t,t);
        }
    }
}
/*******************Segment Tree*********************/
struct node{
    int sum,max;
}tree[MAXN<<2];
void build(int k,int l,int r){
    if(l==r){
        tree[k].sum = tree[k].max = wei[l];
        return;
    }
    int mid = l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
    tree[k].max = max(tree[k<<1].max,tree[k<<1|1].max);
}
int queryMax(int k,int l,int r,int x,int y){
    if(x>r||y<l)return -INF;
    if(x<=l&&y>=r)return tree[k].max;
    int mid = l+r>>1;
    int left,right;
    left = queryMax(k<<1,l,mid,x,y);
    right = queryMax(k<<1|1,mid+1,r,x,y);
    return max(left,right);
}
int querySum(int k,int l,int r,int x,int y){
    if(x>r||y<l)return 0;
    if(x<=l&&y>=r)return tree[k].sum;
    int ans = 0;
    int mid = l+r>>1;
    ans+=querySum(k<<1,l,mid,x,y);
    ans+=querySum(k<<1|1,mid+1,r,x,y);
    return ans;
}
void modify(int k,int l,int r,int pos,int val){
    if(r<pos||l>pos)return;
    if(l==r&&l==pos){
        tree[k].sum = tree[k].max = val;
        return;
    }
    int mid = l+r>>1;
    modify(k<<1,l,mid,pos,val);
    modify(k<<1|1,mid+1,r,pos,val);
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
    tree[k].max = max(tree[k<<1].max,tree[k<<1|1].max);
}
inline int swap(int &x,int &y){ x = x^y;y = y^x;x = x^y; }
int rangeMAX(int u,int v){
    int ans = -INF;
    while(track[u]!=track[v]){
        if(dep[track[u]]<dep[track[v]])swap(u,v);
        ans = max(ans,queryMax(1,1,n,id[track[u]],id[u]));
        u = father[track[u]];
    }
    if(dep[u]>dep[v])swap(u,v);
    ans = max(ans,queryMax(1,1,n,id[u],id[v]));
    return ans;
}
int rangeSum(int x,int y){
    int ans = 0;
    while(track[x]!=track[y]){
        if(dep[track[x]]<dep[track[y]])swap(x,y);
        ans += querySum(1,1,n,id[track[x]],id[x]);
        x = father[track[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=querySum(1,1,n,id[x],id[y]);
    return ans;
}
int rangeModify(int pos,int val){
    modify(1,1,n,id[pos],val);
}
char cmd[10];
int main(){
    n = read();
    int u,v;
    for(int i = 1;i<n;i++){
        u = read(),v = read();
        add(u,v,1);
        add(v,u,1);
    }
    for(int i = 1;i<=n;i++)w[i] = read();
    int q = read();
    root = 1;
    dfs1(1,1);
    dfs2(root,root);
    build(1,1,n);
    while(q--){
        scanf("%s",cmd);
        if(cmd[1]=='H'){
            u = read(),v = read();
            rangeModify(u,v);
        }
        if(cmd[1] == 'M'){
            u = read(),v = read();
            printf("%d\n",rangeMAX(u,v));
        }
        if(cmd[1] == 'S'){
            u = read(),v = read();
            printf("%d\n",rangeSum(u,v));
        }
    }
    return 0;
}