//
// Created by dhy on 18-8-4.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int a[2005],Fmax[2005][2050],Fmin[2005][2005];
int sum[2005] = {0},n;
int main(void){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        a[i+n] = a[i];

    }
    for(int i = 1;i<=n+n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    for(int i = (n<<1)-1;i>=1;i--) {
        for (int j = i + 1; j < i + n; j++) {
            Fmin[i][j] = 0x7ffffff / 2;
            for (int k = i; k < j; k++) {
                Fmax[i][j] = max(Fmax[i][j], Fmax[i][k] + Fmax[k + 1][j] + sum[j] - sum[i - 1]);
                Fmin[i][j] = min(Fmin[i][j], Fmin[i][k] + Fmin[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
        int maxx = 0,minn = 0x7fffff;
        for(int i = 1;i<=n;i++){
            maxx = max(maxx,Fmax[i][i+n-1]);
            minn = min(minn,Fmin[i][i+n-1]);
        }
        cout<<minn<<endl<<maxx<<endl;
    return 0;
}