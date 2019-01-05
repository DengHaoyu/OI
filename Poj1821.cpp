//
// Created by dhy on 18-12-22.
//
#include <cstring>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
struct worker{int si,li,pi;}workers[110];
bool operator<(const worker &w1,const worker &w2){return w1.si<w2.si;}
int F[110][16010];
int cal(int i,int k){
    return F[i-1][k]-workers[i].pi*k;
}
int n,m;
int main() {
    cin>>n>>m;
    for(int i = 1;i<=m;i++)cin>>workers[i].li>>workers[i].pi>>workers[i].si;
    sort(workers+1,workers+m+1);
    for(int i = 1;i<=m;i++){
        deque<int> q;
        for(int k = max(0,workers[i].si-workers[i].li);k <= workers[i].si-1;k++){
            while(!q.empty()&&cal(i,q.back())<=cal(i,k))q.pop_back();
            q.push_back(k);
        }
        for(int j = 1;j<=n;j++){
            F[i][j] = max(F[i-1][j],F[i][j-1]);
            if(j>=workers[i].si){
                while(!q.empty()&&q.front()<j-workers[i].li)q.pop_front();
                if(!q.empty())F[i][j] = max(F[i][j],cal(i,q.front())+workers[i].pi*j);
            }
        }
    }
    cout<<F[m][n]<<endl;
    return 0;
}