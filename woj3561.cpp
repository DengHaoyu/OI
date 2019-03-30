#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100010;
const int MAXM = MAXN-1;
const int INF = 0x3f3f3f3f;
struct edge{int f,t,w,next;bool operator<(const edge &e2)const {return w>e2.w;}}edges[MAXM<<1];
int n ,Q;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+c-'0';c = getchar(); }
    return x*f;
}
struct query{int len,root,id,ans;}querys[(int)1e5+10];
int fa[MAXN];
int wei[MAXN];
int find(int x){
    return  fa[x]==x?x:fa[x] = find(fa[x]);
}
void unionn(int x,int y){
    int fx = find(x);int fy = find(y);
    fa[fy] = fx;
    wei[fx]+=wei[fy];
}
bool cmp1(const query&q1,const query&q2){
    return q1.len>q2.len;
}
bool cmp2(const query&q1, const query &q2){
    return q1.id<q2.id;
}
int main(){
    n = read();Q = read();
    int f,t,w;
    for(int i = 1;i<=n-1;i++){
        f = read(), t = read(),w = read();
        edges[i].f = f;edges[i].t = t; edges[i].w = w;
    }
    int root,K;
    for(int i = 1;i<=Q;i++){
        K = read(),root = read();
        querys[i].len = K;querys[i].root = root;
        querys[i].id = i;
    }
    sort(querys+1,querys+Q+1,cmp1);
    sort(edges+1,edges+n);
    int pos = 1;
    for(int i = 1;i<=n;i++)fa[i] = i,wei[i] = 1;
    for(int i = 1;i<=Q;i++){
        while(pos<n&&edges[pos].w>=querys[i].len)unionn(edges[pos].f,edges[pos].t),pos++;
        querys[i].ans = wei[find(querys[i].root)]-1;
    }
    sort(querys+1,querys+Q+1,cmp2);
    for(int i = 1;i<=Q;i++){
        printf("%d\n",querys[i].ans);
    }
    return 0;
}


