#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> G[5010];
int vis[5010];
namespace tree{
    vector<int> ans;
    void dfs(int x){
        vis[x] = true;
        ans.push_back(x);
        for(int i = 0;i<G[x].size();i++){
            if(!vis[G[x][i]])dfs(G[x][i]);
        }
    }
    void main(){
        dfs(1);
        for(int i = 0;i<ans.size();i++)cout<<ans[i]<<' ';
    }
}
int n,m;
int edge[5010][2];
namespace ringBasedTree{
    vector<int> ans,temp;
    int del_f,del_t;
    bool chect(int u,int v){
        if((u==del_f&&v==del_t)||(u==del_t&&v==del_f)){
            return false;
        }
        return true;
    }
    void dfs(int x){
        vis[x] = true;
        temp.push_back(x);
        for(int i = 0;i<G[x].size();i++){
            if(chect(x,G[x][i])&&!vis[G[x][i]]){
                dfs(G[x][i]);
            }
        }
    }
    void main(){
        for(int i = 1;i<=n;i++)ans.push_back(9999);
        for(int i = 1;i<=m;i++){
                memset(vis,false, sizeof(vis));
                del_f = edge[i][0],del_t = edge[i][1];
                temp.clear();
                dfs(1);
                if(temp<ans&&temp.size()==n)ans = temp;
        }
        for(int i = 0;i<ans.size();i++)cout<<ans[i]<<' ';
    }
}
int main(void){
    cin>>n>>m;
    int x,y;
    for(int i = 1;i<=m;i++){
        cin>>x>>y;
        edge[i][0] = x;
        edge[i][1] = y;
        G[x].push_back(y),G[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)sort(G[i].begin(),G[i].end());
    if(m==n-1){
        tree::main();
    }else{
        ringBasedTree::main();
    }
    return 0;
}
