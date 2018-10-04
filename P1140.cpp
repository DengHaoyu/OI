//
// Created by dhy on 18-8-5.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int map[200][200];
int F[150][150];
int main(void){
    map['A']['A'] = 5;
    map['A']['C'] = -1;
    map['A']['G'] = -2;
    map['A']['T'] = -1;
    map['A']['-'] = -3;
    map['C']['A'] = -1;
    map['C']['C'] = 5;
    map['C']['G'] = -3;
    map['C']['T'] = -2;
    map['C']['-'] = -4;
    map['G']['A'] = -2;
    map['G']['C'] = -3;
    map['G']['G'] = 5;
    map['G']['T'] = -2;
    map['G']['-'] = -2;
    map['T']['A'] = -1;
    map['T']['C'] = -2;
    map['T']['G'] = -2;
    map['T']['T'] = 5;
    map['T']['-'] = -1;
    map['-']['A'] = -3;
    map['-']['C'] = -4;
    map['-']['G'] = -2;
    map['-']['T'] = -1;
    string str1,str2;
    ios::sync_with_stdio(false);
    int k;
    cin>>k>>str1>>k>>str2;
    for(int i = 1;i<=str1.size();i++){
        for(int j = 1;j<=str2.size();j++)
            F[i][j] = -9999000;
    }
    str1.insert(0,1,'0');
    str2.insert(0,1,'0');
    for(int i = 1;i<str1.size();i++)
        F[i][0] = F[i-1][0]+map[str1[i]]['-'];
    for(int i = 1;i<str2.size();i++)
        F[0][i] = F[0][i-1]+map[str2[i]]['-'];
    for(int i = 1;i<str1.size();i++)
        for(int j = 1;j<str2.size();j++){
            F[i][j] = F[i-1][j-1]+map[str1[i]][str2[j]];
            F[i][j] = max(F[i][j],F[i-1][j]+map[str1[i]]['-']);
            F[i][j] = max(F[i][j],F[i][j-1]+map[str2[j]]['-']);
        }
    cout<<F[str1.size()-1][str2.size()-1];
    return 0;
}
