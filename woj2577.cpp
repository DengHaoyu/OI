//
// Created by dhy on 19-2-4.
//
#include <iostream>
using namespace std;
const int MAXN = (int)1e5+10;
int a[MAXN];int b[MAXN];
const int INF = 0x3f3f3f3f;
int n;
struct node{int minn,maxx;}tree[MAXN<<2];
void build(int k,int l,int r){
    if(l==r){
        tree[k].maxx = tree[k].minn = a[l];
        return;
    }
    int mid = l+r>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    tree[k].minn = min(tree[k<<1].minn,tree[k<<1|1].minn);
    tree[k].maxx = max(tree[k<<1].maxx,tree[k<<1|1].maxx);
}
int queryMin(int k,int l,int r,int x,int y){
    if(x>r||y<x)return INF;
    if(l>=x&&r<=y)return tree[k].minn;
    int mid = l+r>>1;
    int ans1 = INF,ans2 = INF;
    if(x<=mid)ans1 = queryMin(k<<1,l,mid,x,y);
    if(y>mid)ans2 = queryMin(k<<1|1,mid+1,r,x,y);
    return min(ans1,ans2);
}
int queryMax(int k,int l,int r,int x,int y){
    if(x>r||y<l)return -INF;
    if(l>=x&&r<=y)
        return tree[k].maxx;
    int mid = l+r>>1;
    int ans1 = -INF,ans2 = -INF;
    if(x<=mid)ans1 = queryMax(k<<1,l,mid,x,y);
    if(y>mid)ans2 = queryMax(k<<1|1,mid+1,r,x,y);
    return max(ans1,ans2);
}
long long cal(int pos){
    long long ans = 1LL*queryMin(1,1,n,pos-b[pos]+1,pos)*queryMax(1,1,n,pos-b[pos]+1,pos);
    return ans;
}
int main(){
    cin>>n;
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++)cin>>b[i];
    build(1,1,n);
    for(int i = 1;i<=n;i++)cout<<cal(i)<<endl;
    return 0;
}
