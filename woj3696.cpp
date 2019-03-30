//
// Created by dhy on 19-2-12.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct edge{int f,t,w,color;bool operator<(const edge&e2)const { return w==e2.w?color<e2.color:w<e2.w;}};
const int MAXN = 100010;
int V,E,need;
edge edges[MAXN];
int top;
int fa[MAXN];
inline int find(int x){return x==fa[x]?x:fa[x] = find(fa[x]);}
inline bool judge(int x,int y){return find(x)==find(y);}
inline void unionn(int x,int y){fa[find(y)]=find(x);}
void init(){for(int i = 1;i<=V;i++)fa[i] = i;}
int ans = 0;
bool check(int x){
    for(int i = 1;i<=top;i++)if(edges[i].color==0)edges[i].w+=x;
    init();
    int tot = 0,white = 0;
    sort(edges+1,edges+1+top);
    int MST = 0;
    for(int i = 1;i<=top;i++){
        if(judge(edges[i].f,edges[i].t))continue;
        unionn(edges[i].f,edges[i].t);
        white+=1-edges[i].color;
        tot++;
        MST+=edges[i].w;
        if(tot>=V-1){
            break;
        }
    }
    for(int i = 1;i<=top;i++)if(edges[i].color==0)edges[i].w-=x;
    ans = MST;
    return white>=need;
}
int main(){
    cin>>V>>E>>need;
    int f,t,w,color;
    for(int i = 1;i<=E;i++){
        cin>>f>>t>>w>>color;
        f++,t++;
        edges[++top].f = f;edges[top].t = t;edges[top].w = w;edges[top].color = color;
    }
    int l = -100,r = 100;
    while(l<r){
        int mid = l+r+1>>1;
        if(check(mid))l = mid;
        else r = mid-1;
    }
    check(l);
    cout<<ans-l*need;
    return 0;
}