//
// Created by dhy on 18-12-31.
//
#include <iostream>
#include <deque>
using namespace std;
long long F[100010];
long long s[100010];
long long work(int j){return F[j-1]-s[j];}
int main(){
    long long N,K;
    cin>>N>>K;
    for(int i = 1;i<=N;i++){cin>>s[i];s[i]+=s[i-1];}
    deque<int> q;
    for(int i = 1;i<=K;i++){
        F[i] = s[i];
        while(!q.empty()&&work(q.back())<=work(i))q.pop_back();
        q.push_back(i);
    }
    for(int i = K+1;i<=N;i++){
        while(!q.empty()&&q.front()<i-K)q.pop_front();
        while(!q.empty()&&work(q.back())<=work(i))q.pop_back();
        q.push_back(i);
        F[i] = work(q.front())+s[i];
    }
    cout<<F[N];
    return 0;
}
