//
// Created by dhy on 19-3-24.
//
#include <cstdio>
#include <cstdlib>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+(c^'0');c = getchar(); }
    return x*f;
}
const int MAXN = (int)3e5+10;
const int INF = 0x3f3f3f3f;
int tree[MAXN][2],val[MAXN],sum[MAXN],cnt[MAXN],dat[MAXN];
int fa[MAXN];
int top,root;
int newNode(int v){
    val[++top] = v,sum[top] = cnt[top] = 1;
    dat[top] = rand();
    return top;
}
void pushup(int x){sum[x] = sum[tree[x][1]]+sum[tree[x][0]]+cnt[x];}
void rotate(int &y,int d){
    int x = tree[y][d];
    tree[y][d] = tree[x][d^1];
    tree[x][d^1] = y;
    sum[x] = sum[y];
    pushup(y);
    y = x;
}
void insert(int &p,int v){
    if(!p){
        p = newNode(v);return;
    }
    if(val[p]==v){
        cnt[p]++;pushup(p);
        return;
    }
    if(val[p]<v){
        insert(tree[p][1],v);
        if(dat[tree[p][1]]<dat[p])rotate(p,1);
    }else if(val[p]>v){
        insert(tree[p][0],v);
        if(dat[tree[p][0]]<dat[p])rotate(p,0);
    }
    pushup(p);
}
void del(int &p,int v){
    if(!p)return;
    if(val[p]==v){
        if(cnt[p]>1){
            cnt[p]--;pushup(p);
            return;
        }
        if(tree[p][0]||tree[p][1]){
            if(!tree[p][1]||tree||dat[tree[p][0]]>dat[tree[p][1]]){
                rotate(p,1);del(tree[p][1],v);
            }else{
                rotate(p,0);del(tree[p][0],v);
            }
            pushup(p);
        }else{
            p = 0;
            return;
        }
    }
    del(tree[p][v>val[p]],v);
    pushup(p);
}
int fromRank(int &p,int rank){
    if(!p)return INF;
    if(rank<=sum[tree[p][0]])return fromRank(tree[p][0],rank);
    if(rank>sum[tree[p][0]]&&rank<=sum[tree[p][0]]+cnt[p])return val[p];
    return fromRank(tree[p][1],rank-sum[tree[p][0]]-cnt[p]);
}
int getRank(int &p,int v){
    if(!p)return 0;
    if(v==val[p])return sum[tree[p][0]]+cnt[p];
    if(v<val[p])return getRank(tree[p][0],v);
    return getRank(tree[p][v>val[p]],v)+sum[tree[p][0]]+cnt[p];
}
int getPre(int v){
    int ans = 1;int p = root;
    while(p){
        if(v==val[p]){
            if(!tree[p][0]){
                p = tree[p][0];
                while(!tree[p][1])p = tree[p][1];
                ans = p;
            }
            break;
        }
        if(val[p]<v&&val[p]>val[ans])ans = p;
        p = tree[p][v>val[p]];
    }
    return ans;
}
int getNext(int v){
    int p = root;int ans = 2;
    while(p){
        if(val[p]==v){
            if(!tree[p][1]){
                p = tree[p][1];
                while(!tree[p][0])p = tree[p][0];
                ans = p;
            }
            break;
        }
        if(val[p]>v&&val[p]<val[ans])ans = p;
        p = tree[p][v>val[p]];
    }
    return ans;
}
void build(){
    newNode(-INF),newNode(INF);
    root = 1;
    tree[1][1] = 2;
}
int main(){
    int n,m;n = read();
    int op,x;
    int t;
    build();
    while(n--){
        op = read(),x = read();
        switch (op){
            case 0:
                insert(root,x);
                break;
            case 1:
                del(root,x);
                break;
            case 2:
                printf("%d \n",fromRank(root,x+1));
                break;
            case 3:
                t = getRank(root,val[getPre(x)]);
                printf("%d \n",t==1?-1:t-1);
                break;
            case 4:
                t = getPre(x);
                printf("%d \n",t==1?-1:val[t]);
                break;
            case 5:
                t = getNext(x);
                printf("%d \n",t==2?-1:val[t]);
                break;
            default:
                continue;
        }
    }
    return 0;
}