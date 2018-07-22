//
// Created by dhy on 18-7-11.
//

//TODO WHO CHANGED MY VALUE OF N, FUCK U
#include <iostream>
#include<stdlib.h>
using namespace std;
int num_map[27]{-1};
int addend[27];
int sum[28];
int command[27];
int N;
int *index[3] = {addend,command,sum};
int lengthOfSum;
bool num_used[27];
void print(){
    for(int i = 0;i<N;i++)
        cout<<num_map[i]<<' ';
    cout<<endl;
}
bool judge(){
    int over = 0;
    int j = lengthOfSum;
    for(int i = N;i>=0;i++){
        int ts = num_map[addend[i]]+num_map[command[i]];
        if(ts>=N){
            over = ts/N;
            ts-=ts%N;
        }
        if(ts!=sum[j]){
            return false;
        }
    }
    if(j!=0&&over!=sum[0]){
        return false;
    }
    return true;
}
void dfs(int ind,int pos){
    if(ind==2&&pos==0judge()){
        print();
        exit(0);
    }
    if(pos==0){
        dfs(ind+1,pos);
    }else{

    }

}
int main(){
    string str;
    cin>>N;
    cin>>str;
    for(int i = 0;i<N;i++)
        addend[i] = str[i]-'A';
    cin>>str;
    for(int i = 0;i<N;i++)
        command[i] = str[i]-'A';
    cin>>str;
    lengthOfSum = str.size();
    for(int i = 0;i<str.size();i++)
        sum[i] = str[i]-'A';
    return 0;
}



