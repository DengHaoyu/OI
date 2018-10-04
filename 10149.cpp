//
// Created by dhy on 18-8-17.
//
#include <iostream>
#include <algorithm>
using namespace std;
int w[101];
unsigned long long F[51][51];
int main(void){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>w[i];
        w[i+n] = w[i];
    }
    for(int i = 1;i<=2*n;i++)for(int j = 1;j<=n*2;j++)F[i][j] = 0x7fffffff/2;

    for(int i = (n<<1)-1;i>0;i--) {
        for (int j = i + 1; j <= i + n; j++) {
            for (int k = i+1; k < j; k++) {
                F[i][j] = min(F[i][j], F[i][k] + F[k + 1][j] + w[i] * w[j] * w[k]);
            }
        }
    }
    unsigned long long ans = 0x7fffffff/2;
    for(int i = 1;i<=n;i++)ans = min(ans,F[i][i+n-1]);
    cout<<ans;
    return 0;
}
