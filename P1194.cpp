//
// Created by dhy on 18-8-6.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{
    int from,to,w;
}edges[5500000];
int cnt = 0;
bool cmp(edge e1,edge e2){
    return e1.w<e2.w;
}
void add(int from,int to,int w){
    edges[++cnt].from = from;
    edges[cnt].to = to;
    edges[cnt].w = w;
}
int father[500001];
int find(int x){
    if(father[x]!=x)father[x] = find(father[x]);
    return father[x];
}
void unionn(int x,int y){
    father[find(x)] = find(y);
}
bool judge(int x,int y){
    return find(x)==find(y);
}
int main(void){
    int A,B;
    ios::sync_with_stdio(false);
    cin>>A>>B;
    int t;
    for(int i = 1;i<=B;i++){
        father[i] = i;
        add(i,B+1,A);
        add(B+1,i,A);
    }

    for(int i = 1;i<=B;i++) {
        for (int j = 1; j <= B; j++) {
            cin >> t;
            if (i<j&&t != 0) {
                add(i, j, t);
            }
        }
    }
    sort(edges+1,edges+cnt+1,cmp);
    int ans = 0,c = 0;
    for(int i = 1;i<=cnt;i++){
        if(!judge(edges[i].from,edges[i].to)){
            unionn(edges[i].from,edges[i].to);
            ans+=edges[i].w;
            c++;
        }
        if(c==B-1){
            break;
        }
    }
    add(-1,1,0);
    for(int i = 1;i<=B;i++)if(father[i] == i)ans+=A;

    cout<<ans;
    return  0;
}