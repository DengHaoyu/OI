//
// Created by dhy on 18-8-11.
//
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct voter{
    int preffer,price;
    bool operator<(voter v2){
        return price<v2.price;
    }
};
int top = 0;
voter vs[30001];
int parties[3001];
int n,m;
int ans = 0x7ffffff;
void search(int index,int cost){
    if(index==top+1)return;
    if(cost>ans)return;
    if(*max_element(parties+1,parties+1+m)==parties[1]){
        ans = cost;
        return;
    }
    parties[vs[index].preffer]--;
    search(index+1,cost+vs[index].price);
    parties[vs[index].preffer]++;
    search(index+1,cost);

}

int main(){
    memset(parties,0, sizeof(parties));
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int tx,ty;
        cin>>tx>>ty;
        if(tx==1)continue;
        vs[++top].preffer = tx;
        vs[top].price = ty;
        parties[vs[top].preffer]++;
    }
//    int toGet = maxx-parties[1]+1;
//    for(int i = 1;i<=n;i++){
//        if(vs[i].preffer!=1){
//            ans+=vs[i].price;
//            toGet--;
//        }
//        if(toGet==0){
//            break;
//        }
//    }
    search(0,0);
    cout<<ans;
    return 0;
}
