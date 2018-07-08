//
// Created by dhy on 18-7-6.
//
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct fruit{
    int m;
    bool operator <(const fruit &f1)const {
        return m > f1.m;
    }
};
int main(){
    priority_queue<fruit> que;
    int n,t;
    cin>>n;
    fruit tf;
    long long ans = 0;
    for(int i = 0;i<n;i++){
        cin>>tf.m;
        que.push(tf);
    }
    fruit f1,f2;
    for(int i = 0;i<n-1;i++){
        f1 = que.top();
        que.pop();
        f2 = que.top();
        que.pop();
        ans+=f1.m+f2.m;
        que.push(*new fruit{f1.m+f2.m});
    }
    cout<<ans;
}