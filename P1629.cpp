// luogu-judger-enable-o2
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
struct e{
    int next,to,w;
}Edges[100000+1];
int head[1000+1];
int e_cnt = 0;
void add(int from,int to,int w){
    Edges[++e_cnt].next = head[from];
    Edges[e_cnt].to = to;
    Edges[e_cnt].w = w;
    head[from] = e_cnt;
}

int main() {
    int N,M;
    ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i = 1;i<=M;i++){
        int U,V,W;
        cin>>U>>V>>W;
        add(U,V,W);
    }

    return 0;
}