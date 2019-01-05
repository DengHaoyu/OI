//
// Created by dhy on 18-12-15.
//
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
bool judge(string s){
    int len = s.size()-1;
    if(len==0)
        return true;
    int mid = (len)>>1;
    for(int i = 0;i<=mid;i++){
        if(s[i]!=s[len-i])return false;
    }
    return true;
}
int cnt[30];
int main(){
    int T;
    cin>>T;
    string str;
    while(T--){
        cin>>str;
        if(!judge(str))cout<<str<<endl;
        else{
            string temp;
            memset(cnt,0, sizeof(cnt));
            for(int i = 0;i<str.size();i++)cnt[str[i]-'a']++;
                for(int i = 'a'-'a';i<='z'-'a';i++) {
                    if (cnt[i] != 0){
                        temp.append(cnt[i],i+'a');
                        cnt[i] = 0;
                    }
                }

            if(judge(temp))cout<<-1<<endl;else cout<<temp<<endl;
        }
    }
    return 0;
}