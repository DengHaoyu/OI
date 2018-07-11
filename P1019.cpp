//
// Created by dhy on 18-7-11.
//
//fuck String !
#include <iostream>
#include<string>
#include<stack>
using namespace std;
string ans;
int word_used[21]{0};
string words[21];
int n = 0;
void add(string str){
    if(ans == ""){
        ans.append(str);
        return;
    }
    string temp;
    for(int i = ans.size()-1;i>=0;i++){
        temp.insert(0,1,ans[i]);
        if(temp == str.substr(0,ans.size()-1-i&&))
    }
}
int main(){
    add("at");
    add("touch");
    add("chinese");
    cout<<ans;
    return 0;
}



