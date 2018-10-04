//
// Created by dhy on 18-8-13.
//
//线段树板子题
//P3372
#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    long long sum;
    long long add;
}segTree[100000*4+1];
long long a[100000+1];
void Add(int k,int l,int r,long long v){
    segTree[k].add+=v;
    segTree[k].sum+=v*(r-l+1);
}
void pushdown(int k,int l,int r,int mid){
    if(segTree[k].add==0)return;
    Add(k*2,l,mid,segTree[k].add);
    Add(k*2+1,mid+1,r,segTree[k].add);
    segTree[k].add = 0;
}
long long query(int k,int l,int r,int x,int y){
    if(l>=x&&r<=y)return segTree[k].sum;
    int mid = l+r>>1;
    pushdown(k,l,r,mid);
    long long ans = 0;
    if(x<=mid)ans+=query(k*2,l,mid,x,y);
    if(mid<y)ans+=query(k*2+1,mid+1,r,x,y);
    return ans;
}
void modify(int k,int l,int r,int x,int y,long long v){
    if(l>=x&&r<=y){//完全包含就打上标签
        return Add(k,l,r,v);
    }
    int mid = l+r>>1;
    pushdown(k,l,r,mid);
    if(x<=mid)modify(k*2,l,mid,x,y,v);
    if(mid<y)modify(k*2+1,mid+1,r,x,y,v);
    segTree[k].sum=segTree[k*2].sum+segTree[k*2+1].sum;
}
void build(int k,int l,int r){
    if(l==r){
        segTree[k].sum = a[l];
        return;
    }
    int mid = l+r>>1;
    build(k*2,l,mid);
    build(k*2+1,mid+1,r);
    segTree[k].sum=segTree[k*2].sum+segTree[k*2+1].sum;
}
int main(void){
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    int temp,x,y,k;
    for(int i = 1;i<=N;i++){
        cin>>a[i];
    }
    build(1,1,N);
    for(int i = 1;i<=M;i++){
        cin>>temp;
        if(temp==1){
             cin>>x>>y>>k;
             modify(1,1,N,x,y,k);
        }else{
            cin>>x>>y;
            cout<<query(1,1,N,x,y)<<endl;
        }
    }
    return 0;
}
