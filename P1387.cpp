//
// Created by dhy on 19-1-5.
//
#include <iostream>
using namespace std;
int map[110][110];
int n,m;
int sum[110][110];
inline int getSum(int i,int j,int l){
    return sum[i][j] - sum[i-l][j]-sum[i][j-l]+sum[i-l][j-l];
}
bool work(int len){
    for(int i = 1;i<=n-len;i++)
        for(int j = 1;j<=m-len;j++){
            if(getSum(i+len,j+len,len)==len*len)return true;
        }
        return false;
}
int main(){
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+map[i][j];
        }
    }
    int l = 1,r = min(m,n)+1;
    while(l<r){
        int mid = l+r+1>>1;
        if(work(mid))l = mid;
        else r = mid-1;
    }
    cout<<l;
    return 0;
};
