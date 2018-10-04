//
// Created by dhy on 18-9-15.
//
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int f,t,w;
}edges[10000000];
bool cmp(const edge& e1,const edge &e2){return e1.w<e2.w;}

int father[10000000];
int find(int x){
    if(father[x]!=x){
        father[x] = find(father[x]);
    }
    return father[x];
}
void uni(int x,int y){
    father[find(y)] = find(x);
}
inline bool judge(int x,int y){
    return find(x)==find(y);
}
int top = 0;
int kruskal(int n,int e){
    sort(edges+1,edges+top+1,cmp);
    int cnt = 0;
    int ans = 0;
    for(int i = 1;i<=e;i++){
        int x = edges[i].f;
        int y = edges[i].t;
        if(!judge(x,y)){
            cnt++;
            uni(x,y);
            ans+=edges[i].w;
        }
        if(cnt==n-1)return ans;
    }
    if(cnt!=n-1)return -233;
}
int main(void){
    ios::sync_with_stdio(false);
    int n,e;
    cin>>n>>e;
    int f,t,w;
    for(int i = 1;i<=n;i++)father[i] = i;

    for(int i = 1;i<=e;i++){
        cin>>f>>t>>w;
        edges[++top].f = f;
        edges[top].t = t;
        edges[top].w = w;
    }
    int ans = kruskal(n,e);
    if(ans==-233)cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}