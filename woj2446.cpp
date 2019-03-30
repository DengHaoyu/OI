//
// Created by dhy on 19-2-18.
//
#include <iostream>
using namespace std;
const int MAXN = 100010;
int tree[MAXN][2];int cnt[MAXN];int sum[MAXN];
int val[MAXN];int tag[MAXN];int fa[MAXN];
int root;int tot;
int n,m;
int which(int x){return tree[fa[x]][1]==x;}
void pushup(int x){sum[x] = sum[tree[x][1]]+sum[tree[x][0]]+cnt[x];}
void rotate(int x){
    int y = fa[x],z = fa[y],d = which(x),w = tree[x][d^1];
    tree[y][d] = w;fa[w] = y;
    tree[z][which(y)] = x;fa[x] = z;
    tree[x][d^1] = y;fa[y] = x;
    pushup(y);pushup(x);
}
void splay(int x,int tar = 0){
    while (fa[x]!=tar){
        int y = fa[x], z = fa[y];
        if(z!=tar) {
            if (which(x) == which(y))rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!tar)root = x;
}
void pushdown(int x){
    if(tag[x]){
        swap(tree[x][1],tree[x][0]);
        tag[tree[x][0]]^=1;tag[tree[x][1]]^=1;
        tag[x] = 0;
    }
}
void insert(int v){
    int curr = root,p = 0;
    while(curr&&val[curr]!=v){
        p = curr;curr = tree[curr][v>val[curr]];
    }
    if(curr){
        cnt[curr]++;
    }else{
        curr = ++tot;
        if(p)tree[p][v>val[p]] = curr;
        sum[curr] = cnt[curr] = 1;
        val[curr] = v;
        fa[curr] = p;
    }
    splay(curr);
}
int kth(int rank){
    int curr = root;
    while(true){
        pushdown(curr);
        if(tree[curr][0]&&rank<=sum[tree[curr][0]]){
            curr = tree[curr][0];
        }else if(rank>cnt[curr]+sum[tree[curr][0]]){
            rank-=cnt[curr]+sum[tree[curr][0]];
            curr = tree[curr][1];
        }else return curr;
    }
}
void reverse(int l,int r){
    int x = kth(l),y = kth(r+2);
    splay(x);splay(y,x);
    tag[tree[y][0]]^=1;
}
void dfs(int x){
    pushdown(x);
    if(tree[x][0])dfs(tree[x][0]);
    if(val[x]&&val[x]<=n)cout<<val[x]<<' ';
    if(tree[x][1])dfs(tree[x][1]);
}
int main(){
    cin>>n>>m;
    int x,y;
    for(int i = 0;i<=n+1;i++)
        insert(i);
    for(int i = 1;i<=m;i++){
        cin>>x>>y;
        reverse(x,y);
    }
    dfs(root);
    return 0;
}