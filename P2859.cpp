//
// Created by dhy on 18-8-30.
//
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct cow{
    int start,end,id,p;
    bool operator<(cow c2){return start<c2.start;}
};
struct machine{
    int end,rank;
};
bool operator<(machine m1,machine m2){
    return m1.end>m2.end;
}
int plan[50001];
cow cows[50001];
int main(void){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>cows[i].start>>cows[i].end;
        cows[i].id = i;
    }
    int cnt = 0;
    priority_queue<machine> ms;
    sort(cows+1,cows+n+1);
    machine tm;
    tm.end = cows[1].end;
    tm.rank = 1;
    cows[1].p = 1;
    ms.push(tm);
    ++cnt;

    for(int i = 2;i<=n;i++){
        machine tm;
        if(ms.top().end<cows[i].start){
            tm = ms.top();
            ms.pop();
            tm.end = cows[i].end;
            ms.push(tm);
            cows[i].p = tm.rank;
        }else{
            tm.end = cows[i].end;
            tm.rank = ++cnt;
            cows[i].p = tm.rank;
            ms.push(tm);
        }
    }
    for(int i = 1;i<=n;i++){
        plan[cows[i].id] = cows[i].p;
    }
    cout<<cnt<<endl;
    for(int i = 1;i<=n;i++)cout<<plan[i]<<endl;
    return 0;
}