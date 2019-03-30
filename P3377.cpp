//
// Created by dhy on 19-3-9.
//
#include <iostream>
#include <ext/pb_ds/priority_queue.hpp>
using namespace __gnu_pbds;
using namespace std;
const int MAXN = 100010;
int root[MAXN];
int dep[MAXN];
bool del[MAXN];
int n,m;
__gnu_pbds::priority_queue<int> q[MAXN];
int find(int x){return root[x]==x?x:find(root[x]);}
void unionn(int x,int y){root[find(y)] = find(x);}
bool judge(int x,int y){return find(x)==find(y);}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int v;cin>>v;q[i].push(v);root[i] = i;
    }
    int op,x,y;
    for(int i = 1;i<=m;i++){
        cin>>op;
        if(op==1){
            cin>>x>>y;
            if(judge(x,y)||del[x]||del[y])continue;
            q[find(x)].join(q[find(y)]);
            unionn(x,y);
        }else{
            cin>>x;
            if(del[x])cout<<-1<<endl;
            else{
                del[find(x)] = true;
                cout<<q[find(x)].top()<<endl;
                q[find(x)].pop();
            }
        }
    }
    return 0;
}