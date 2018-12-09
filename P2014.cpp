#include <iostream>
using namespace std;
const int MAXN = 310;
const int MAXM = 310;
int indegree[MAXN];
struct edge{
    int t,w,next;
}edges[MAXN];
int head[MAXN];
int top;
void add(int f,int t,int w) {
    edges[++top].next = head[f];
    edges[top].t = t;
    edges[top].w = w;
 //   indegree[t]++;
    head[f] = top;
}
int score[MAXN];
int F[MAXN][MAXM];
int n,m;

void dfs(int x){
    for(int i = head[x];i!=0; i = edges[i].next){
        int t = edges[i].t;
        dfs(t);
        for(int j = m;j>=0;j--){//为了处理组内选取0个课程的情况
            for(int k = j;k>=0;k--){
                if(j-k>=0){
                    F[x][j] = max(F[x][j],F[x][j-k]+F[t][k]);
                }
            }

        }
    }
    if(x!=0){
        for(int i = m;i>0;i--)F[x][i] = F[x][i-1]+score[x];
    }
}
int main(void){
    cin>>n>>m;
    int si,ki;
    for(int i = 1;i<=n;i++){
        cin>>si>>ki;
        score[i] = ki;
        add(si,i,ki);
    }
    dfs(0);
    cout<<F[0][m];
    return 0;
}
