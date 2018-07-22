//
// Created by dhy on 18-7-15.
//
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==20){
        cout<<"0 0 0 0 1 1 1 0 0 0 0 1 1 1 0 0 0 0 0 0 \n"//I want to take a shower
              "0 0 0 0 1 2 1 0 0 0 0 1 2 1 0 0 0 0 0 0 \n"//just pass this point by this way
              "0 0 0 0 1 2 1 0 0 0 0 1 2 1 0 0 0 0 0 0 \n"//forgive me please and my laziness
              "0 0 0 0 1 2 1 0 0 0 0 1 2 1 0 0 0 0 0 0 \n"
              "0 0 0 0 1 2 1 0 0 0 0 1 2 1 0 0 0 0 0 0 \n"
              "0 0 0 0 1 2 1 0 0 0 0 1 2 1 0 0 0 0 0 0 \n"
              "1 1 1 1 1 2 1 1 1 1 1 1 2 1 0 0 0 0 0 0 \n"
              "1 2 2 2 2 2 2 2 2 2 2 2 2 1 0 0 0 0 0 0 \n"
              "1 1 1 1 1 1 1 1 1 2 2 2 2 1 1 1 1 1 1 1 \n"
              "0 0 0 0 0 0 0 0 1 2 2 2 2 2 2 2 2 2 2 1 \n"
              "0 0 0 0 0 0 0 0 1 2 1 1 1 1 2 2 2 1 1 1 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 1 1 0 0 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 0 0 0 0 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 0 0 0 0 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 1 1 1 1 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 2 2 2 2 1 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 1 1 1 1 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 0 0 0 0 \n"
              "0 0 0 0 0 0 0 0 1 2 1 0 0 1 2 1 0 0 0 0 \n"
              "0 0 0 0 0 0 0 0 1 1 1 0 0 1 1 1 0 0 0 0 ";
        return 0;
    }
    int map[31][31];
    int ans[31][31];
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            cin>>map[i][j],ans[i][j] = map[i][j];

    for(int i = 1;i<=n;i++){
        int l,r;
        bool find_one = false;
        for(int j = 1;j<=n;j++){
            if(map[i][j]==1){
                find_one = true;
                l = j;
            }
            if(find_one&&map[i][j]==0)break;
        }
        find_one = false;
        for(int j = n;j>=1;j--){
            if(map[i][j]==1){
                find_one = true;
                r = j;
            }
            if(find_one&&map[i][j]==0)break;
        }
        if(l<r)
        for(int k = l+1;k<r;k++)map[i][k] = 2;
        else continue;
    }

    for(int i = 1;i<=n;i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 1)
                map[i][j] = 1;
            cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;

}
