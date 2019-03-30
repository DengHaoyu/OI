//
// Created by dhy on 19-3-17.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 30010;
const int INF = 0x3f3f3f3f;
struct edge{
    int t,w,next;
}edges[MAXN<<1];
int head[MAXN];
int top;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
    head[f] = top;
}
int w[MAXN];//former weight
int a[MAXN];
class SegmentTree{
private:
    struct node{int max,sum;}tree[MAXN<<2];
public:
    void build(int k,int l,int r){
        if(l==r){tree[k].sum = tree[k].max = a[l];return;}
        int mid = l+r>>1;
        build(k<<1,l,mid);build(k<<1|1,mid+1,r);
        tree[k].max = max(tree[k<<1].max,tree[k<<1|1].max);
        tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
    }
    void modify(int k,int l,int r,int pos,int v){
        if(l==r){
            tree[k].sum = tree[k].max = v;return;
        }
        int mid = l+r>>1;
        if(pos<=mid)modify(k<<1,l,mid,pos,v);
        else modify(k<<1|1,mid+1,r,pos,v);
        tree[k].max = max(tree[k<<1].max,tree[k<<1|1].max);
        tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
    }
    int querySum(int k,int l,int r,int x,int y){
        if(l>=x&&r<=y)return tree[k].sum;
        if(x>r||y<l)return 0;
        int mid = l+r>>1;
        int ret = 0;
        if(x<=mid)ret+=querySum(k<<1,l,mid,x,y);
        if(y>mid)ret+=querySum(k<<1|1,mid+1,r,x,y);
        return ret;
    }
    int queryMax(int k,int l,int r,int x,int y){
        if(l>=x&&r<=y)return tree[k].max;
        if(x>r||y<l)return -INF;
        int mid = l+r>>1;
        int ret = -INF;
        if(x<=mid)ret = max(ret,queryMax(k<<1,l,mid,x,y));
        if(y>mid)ret = max(ret,queryMax(k<<1|1,mid+1,r,x,y));
        return ret;
    }
};
SegmentTree segmentTree;
int father[MAXN],track[MAXN],dep[MAXN],size[MAXN];
int dfn,id[MAXN],heavyson[MAXN];
void dfs1(int x,int fa){
    dep[x] = dep[fa]+1;
    size[x] = 1;
    father[x] = fa;
    int sonSize = 0;
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(t==fa)continue;
        dfs1(t,x);
        size[x]+=size[t];
        if(size[t]>sonSize)sonSize = size[t],heavyson[x] = t;
    }
}
void dfs2(int x,int tpp){
    track[x] = tpp;
    id[x] = ++dfn;
    a[id[x]] = w[x];
    if(!heavyson[x])return;
    dfs2(heavyson[x],tpp);
    for(int i = head[x];i;i = edges[i].next){
        int t = edges[i].t;
        if(t==father[x]||t==heavyson[x])continue;
        dfs2(t,t);
    }
}
void modifyPoint(int x,int v){
    segmentTree.modify(1,1,dfn,id[x],v);
}
int queryMax(int x,int y){
    int ans = -INF;
    while(track[x]!=track[y]){
        if(dep[track[x]]<dep[track[y]])swap(x,y);
        ans = max(ans,segmentTree.queryMax(1,1,dfn,id[track[x]],id[x]));
        x = father[track[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    return max(ans,segmentTree.queryMax(1,1,dfn,id[y],id[x]));
}
int querySum(int x,int y){
    int ans = 0;
    while(track[x]!=track[y]){
        if(dep[track[x]]<dep[track[y]])swap(x,y);
        ans += segmentTree.querySum(1,1,dfn,id[track[x]],id[x]);
        x = father[track[x]];
    }
    if(dep[x]<dep[y])swap(x,y);
    return ans+segmentTree.querySum(1,1,dfn,id[y],id[x]);
}

int main(){
    int n;scanf("%d",&n);
    int f,t;
    for(int i = 1;i<n;i++){
        scanf("%d %d",&f,&t);
        add(f,t,1);add(t,f,1);
    }
    for(int i = 1;i<=n;i++)scanf("%d",&w[i]);
    int Q;scanf("%d",&Q);
    dfs1(1,1);dfs2(1,1);
    segmentTree.build(1,1,dfn);
    char cmd[10];int u,v;
    while(Q--){
        scanf("%s",cmd);
        if(cmd[0]=='C'){
            scanf("%d %d",&u,&v);
            modifyPoint(u,v);
        }else{
            if(cmd[1]=='M'){
                scanf("%d %d",&u,&v);
                printf("%d\n",queryMax(u,v));
            }else{
                scanf("%d %d",&u,&v);
                printf("%d\n",querySum(u,v));
            }
        }
    }
    return 0;
}