//
// Created by dhy on 19-3-9.
//
#include <cstring>
#include <iostream>
using namespace std;
int tree[30][2];
int son[30],fa[30];
void pre(int x){
    cout<<char(x+'A');
    if(tree[x][0]!=-1)pre(tree[x][0]);
    if(tree[x][1]!=-1)pre(tree[x][1]);
}
void mid(int x){
    if(tree[x][0]!=-1)pre(tree[x][0]);
    cout<<char(x+'A');
    if(tree[x][1]!=-1)pre(tree[x][1]);
}
void back(int x){
    if(tree[x][0]!=-1)pre(tree[x][0]);
    if(tree[x][1]!=-1)pre(tree[x][1]);
    cout<<char(x+'A');
}
int main(){
    memset(tree,-1, sizeof(tree));
    int n;cin>>n;
    char c;
    for(int i = 1;i<=n;i++){
        cin>>c;
        c-='A';
        int id;cin>>id;
        while(id){
            if(!son[c]){
                tree[c][0] = id;
            }else{
                tree[son[c]][1] = id;
            }
            son[c] = id;fa[id] = c;
            cin>>id;
        }
    }
    while(fa[c]!=0)c = fa[c];
    pre(c);cout<<endl;

}