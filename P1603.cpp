//
// Created by dhy on 18-7-5.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    map<string,int> m;
    m.insert(pair<string,int >("one",1));
    m.insert(pair<string,int >("two",2));
    m.insert(pair<string,int >("three",3));
    m.insert(pair<string,int >("four",4));
    m.insert(pair<string,int >("five",5));
    m.insert(pair<string,int >("six",6));
    m.insert(pair<string,int >("seven",7));
    m.insert(pair<string,int >("eight",8));
    m.insert(pair<string,int >("nine",9));
    m.insert(pair<string,int >("ten",10));
    m.insert(pair<string,int >("eleven",11));
    m.insert(pair<string,int >("twelve",12));
    m.insert(pair<string,int >("thirteen",13));
    m.insert(pair<string,int >("fourteen",14));
    m.insert(pair<string,int >("fifteen",15));
    m.insert(pair<string,int >("sixteen",16));
    m.insert(pair<string,int >("seventeen",17));
    m.insert(pair<string,int >("eighteen",18));
    m.insert(pair<string,int >("nineteen",19));
    m.insert(pair<string,int >("twenty",20));
    m.insert(pair<string,int >("a",1));
    m.insert(pair<string,int >("another",1));
    m.insert(pair<string,int >("first",1));
    m.insert(pair<string,int >("second",2));
    m.insert(pair<string,int >("third",3));
    m.insert(pair<string,int >("both",2));
    vector<string> v;
    vector<int> rs;
    for(int i = 0;i<6;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    for(int i = 0;i<6;i++){
        if(m.find(v[i])!=m.end()){
            int j = m.find(v[i])->second;
            if((j*j)%100!=0)rs.push_back(j*j%100);
        }
    }
    if(rs.size()==0){
        cout<<0;
        return 0;
    }
    sort(rs.begin(),rs.end());
    cout<<rs[0];
    for(int i = 1;i<rs.size();i++){
        if(rs[i]<10)cout<<'0'<<rs[i];
        else cout<<rs[i];
    }
    return 0;
}
