//
// Created by dhy on 19-2-9.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = (int)2e5+10;
struct node{long long sum,times;}tree[MAXN<<2];
int a[MAXN];
int read(){
    int x = 0,f = 1;
    char c = getchar();
    while(c<'0'||c>'9'){if(c=='-')f = -1;c = getchar();}
    while(c>='0'&&c<='9'){x = (x<<1)+(x<<3)+(c^'0'); c = getchar();}
    return x*f;
}
void build(int k,int l,int r){
    if(l==r){tree[k].sum = a[l];return;}
    int mid = l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
}
long long query(int k,int l,int r,int x,int y){
    if(y<l||x>r)return 0;
    if(l>=x&&r<=y)return tree[k].sum;
    int mid = l+r>>1;
    return query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y);
}
void modifyPoint(int k,int l,int r){
    if(l==r){
        tree[k].times++;tree[k].sum = sqrt(tree[k].sum);
        return;
    }
    int mid = l+r>>1;
    modifyPoint(k<<1,l,mid);
    modifyPoint(k<<1|1,mid+1,r);
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
}
void modify(int k,int l,int r,int x,int y){
    if(l>=x&&r<=y){
        if(tree[k].times>=6)return;
        int mid = l+r>>1;tree[k].times++;
        modifyPoint(k,l,r);
        return;
    }
    if(y<l||x>r)return;
    int mid = l+r>>1;
    modify(k<<1,l,mid,x,y);
    modify(k<<1|1,mid+1,r,x,y);
    tree[k].sum = tree[k<<1].sum+tree[k<<1|1].sum;
}
int main(){
    int n,m;
    n = read();
    for(int i = 1;i<=n;i++)a[i] = read();
    build(1,1,n);
    m = read();
    int x,l,r;
    for(int i = 1;i<=m;i++){
        x = read(),l = read(),r = read();
        if(x==1){
            printf("%lld\n",query(1,1,n,l,r));
        } else{
            modify(1,1,n,l,r);
        }
    }
    return 0;
}