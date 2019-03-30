//
// Created by dhy on 19-2-5.
//
#include <iostream>
using namespace std;
const int MAXN = 100010;
const long long mod = (int)1e9+7;
long long p[MAXN];long long l_11[MAXN];
struct node{ long long val,tag = -1;}tree[MAXN<<2];
char c[MAXN];
void build(int k,int l,int r){
    if(l==r){
        tree[k].val = c[l]-'0';
        return;
    }
    int mid = l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].val = ((tree[k<<1].val*p[r-mid]%mod)+tree[k<<1|1].val)%mod;
}
void add(int k,int l,int r,long long val){
    tree[k].tag = val;
    tree[k].val = val*l_11[r-l+1];
}
void pushdown(int k,int l,int r){
    if(tree[k].tag==-1)return;
    long long v = tree[k].tag;
    int mid = l+r>>1;
    add(k<<1,l,mid,v);add(k<<1|1,mid+1,r,v);
    tree[k].val = ((tree[k<<1].val*p[r-mid]%mod)+tree[k<<1|1].val)%mod;
    tree[k].tag = -1;

}
void modify(int k,int l,int r,int x,int y,long long v){
    if(x>r||y<l)return;
    if(l>=x&&r<=y){
        tree[k].tag = v;
        return;
    }
    pushdown(k,l,r);
    int mid = l+r>>1;
    if(x<=mid)modify(k<<1,l,mid,x,y,v);
    if(y>mid)modify(k<<1|1,mid+1,r,x,y,v);
    tree[k].val = ((tree[k<<1].val*p[r-mid]%mod)+tree[k<<1|1].val)%mod;
}
long long query(int k,int l,int r,int x,int y){
    if(l>y||r<x)return 0;
    pushdown(k,l,r);
    if(x==l&&r==y){return tree[k].val;}
    int mid = l+r>>1;
    if(y<=mid)return query(k<<1,l,mid,x,y);
    if(x>mid)return query(k<<1|1,mid+1,r,x,y);
    else{
        return (query(k<<1,l,mid,x,mid)*p[y-mid]%mod+query(k<<1|1,mid+1,r,mid+1,y))%mod;
    }
}
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)cin>>c[i];
    int op,l,r,v;
    p[0] = 1,l_11[0] = 0;
    for(int i = 1;i<MAXN;i++){
        p[i] = p[i-1]*10%mod;
        l_11[i] = (l_11[i-1]*10+1)%mod;
    }
    build(1,1,n);
    for(int i = 1;i<=m;i++){
        cin>>op>>l>>r;
        if(op==1){
            l++,r++;
            cout<<query(1,1,n,n-r+1,n-l+1)<<endl;
        }else{
            cin>>v;
            l++,r++;
            modify(1,1,n,n-r+1,n-l+1,v);
        }
    }
    return 0;
}