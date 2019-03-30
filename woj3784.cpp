//
// Created by dhy on 19-3-17.
//
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 100010;
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
int root;
class SegmentTree{
private:
    struct node{int max,sum;}tree[MAXN<<2];
public:
    void build(int k,int l,int r){
        if(l==r){tree[k].sum = tree[k].max = a[l];return;}
        int mid = l+r>>1;
        build(k<<1,l,mid);build(k<<1|1,mid+1,r);
        tree[k].max = min(tree[k<<1].max,tree[k<<1|1].max);
        tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
    }
    void modify(int k,int l,int r,int pos,int v){
        if(l==r){
            tree[k].sum = tree[k].max = v;return;
        }
        int mid = l+r>>1;
        if(pos<=mid)modify(k<<1,l,mid,pos,v);
        else modify(k<<1|1,mid+1,r,pos,v);
        tree[k].max = min(tree[k<<1].max,tree[k<<1|1].max);
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
    int queryMin(int k,int l,int r,int x,int y){
        if(l>=x&&r<=y)return tree[k].max;
        if(x>r||y<l)return INF;
        int mid = l+r>>1;
        int ret = INF;
        if(x<=mid)ret = min(ret,queryMin(k<<1,l,mid,x,y));
        if(y>mid)ret = min(ret,queryMin(k<<1|1,mid+1,r,x,y));
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
int lca(int x,int y){
    while(track[x]!=track[y]){
        if(dep[track[x]]<dep[track[y]])swap(x,y);
        x = father[track[x]];
    }
    return dep[x]<dep[y]?x:y;
}
int main(){
    int n,Q;cin>>n>>Q;
    int f,t;
    for(int i = 1;i<=n;i++){
        cin>>f>>t;
        if(f!=0){
            add(f,i,1);
            w[i] = t;
        }else{
            root = i;w[i] = t;
        }
    }
    dfs1(root,root);dfs2(root,root);
    segmentTree.build(1,1,dfn);
    char opt;int x,y;
    while(Q--){
        cin>>opt;
        if(opt=='Q'){
            cin>>x;
            int LCA = lca(x,root);
            if(x==root)cout<<segmentTree.queryMin(1,1,dfn,1,dfn)<<endl;
            else if(LCA!=x){
                cout<<segmentTree.queryMin(1,1,dfn,id[x],id[x]+size[x]-1)<<endl;
            }else{//这里有问题，要找出x到root的路径中，最靠近x的那个点y再扣掉y的子树
                cout<<min(segmentTree.queryMin(1,1,dfn,1,id[LCA]-1),segmentTree.queryMin(1,1,dfn,id[LCA]+size[LCA],dfn))<<endl;
            }
        }else if(opt=='E')cin>>root;
        else{
            cin>>x>>y;
            segmentTree.modify(1,1,dfn,id[x],y);
        }
    }
    return 0;
}