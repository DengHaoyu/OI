//
// Created by dhy on 18-7-5.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    string org,en,todo;
    cin>>en>>org>>todo;
    map<char,char> relation;
    for(int i = 0;i<org.size();i++){
        if(relation.find(en[i])==relation.end()){
            relation.insert(pair<char,char>(en[i],org[i]));
        }else if(relation.find(en[i])->second==org[i]){//find!
            //pass
        }else{
            cout<<"Failed";
            return 0;
        }
    }
    if(relation.size()<26){
        cout<<"Failed";
        return 0;
    }
    for(int i = 0;i<todo.size();i++){
        if(relation.find(todo[i])==relation.end()){//not exist
            cout<<"Failed";
            return 0;
        }else{
            cout<<relation.find(todo[i])->second;
        }
    }
    return 0;
}