//
// Created by dhy on 19-2-11.
//
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int num[14];
const int MAXN = (int)5e5+10;
bool viss[MAXN];
long long dis[MAXN];
struct edge{
    long long t,w,next;
}edges[MAXN*20];
int head[MAXN];
int topp;
void add(int f,int t,int w) {
    edges[++topp].next = head[f];
    edges[topp].t = t;
    edges[topp].w = w;
    head[f] = topp;
}
void spfa(){
    memset(dis,0x6f,sizeof(dis));
    memset(viss,false,sizeof(viss));
    queue<long long> q;
    int s = 0;
    viss[s] = true;
    dis[s] = 0;
    q.push(s);
    while(!q.empty()){
        long long top = q.front();
        q.pop();
        viss[top] = false;
        for(long long i = head[top];i!=0;i = edges[i].next){
            long long t = edges[i].t;
            if(dis[t]>dis[top]+edges[i].w){
                dis[t] = dis[top]+edges[i].w;
                if(!viss[t]){
                    viss[t] = true;
                    q.push(t);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    long long bmax,bmin;
    cin>>n>>bmin>>bmax;
    for(int i = 1;i<=n;i++)cin>>num[i];
    sort(num+1,num+1+n);
    int mn = num[1];
    for(int i = 0;i<mn;i++){
        for(int j = 2;j<=n;j++){
            add(i,(i+num[j])%mn,num[j]);
        }
    }
    spfa();
    long long ans = 0;
    for(int i = 0;i<mn;i++){
        if(dis[i]>bmax)continue;
        if(dis[i]>bmin){
            ans+=(bmax-dis[i])/mn+1;
        } else{
            ans+=(bmax-dis[i])/mn+1;
            ans-=(bmin-dis[i]+mn-1)/mn;
        }
    }
    cout<<ans;
    return 0;
}
