//
// Created by dhy on 18-8-5.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
const double s = 0.3017471748;
const double c = 0.6982528252;
using namespace std;
string str[101];
double val[101] = {0.0};
double F[101];//the sum of front i numbers
int main(void){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>str[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<str[i].length();j++){
            if(str[i][j]=='s')val[i]+=s;
            if(str[i][j]=='c')val[i]+=c;
        }
    }
    for(int i = 1;i<=n;i++){
        F[i] = max(F[i],F[i-1]+val[i]);
    }
    cout<<F[n];
    return 0;
}
