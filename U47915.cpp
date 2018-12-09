//
// Created by dhy on 18-11-4.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = (int)1e6+10;
struct pos{
    int citizen;
    int location;
    int wei;
    bool operator<(const pos&p2){
        return wei>p2.wei;
    }
}poses[MAXN+10];
int tower[MAXN];
int main(void){
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int t;
    for(int i = 0;i<=MAXN;i++)poses[i].location = i;
    int cnt_pos = 0;
    for(int i = 1;i<=n;i++){
        cin>>t;
        if(poses[t].citizen!=0)cnt_pos++;
        poses[t].citizen++;

    }
    for(int i = 0;i<=MAXN;i++){
        poses[i].wei = poses[i].location*poses[i].citizen;
    }
    sort(poses,poses+MAXN);
    for(int i = 1;i<=k;i++){
        tower[i] = poses[i].location;
    }
    int sum = 0;
    for(int i = 0;i<=cnt_pos;i++){
        for(int j = 1;j<=k;j++){
            sum+=poses[i].citizen*abs(poses[i].location-tower[j]);
        }
    }
    cout<<sum;
    return 0;
}
