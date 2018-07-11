//
// Created by dhy on 18-7-11.
//

//TODO WHO CHANGED MY VALUE OF N, FUCK U
#include <iostream>
#include<stdlib.h>
using namespace std;
int num_map[27];
bool used[14];
int jjjj;
int N;
string addend,summend,ans;
bool judge(){
    string add,summ,an;
    for(int i = 0;i<N;i++){
        add.push_back(num_map[addend[i]-'A']+'0');
        summ.push_back(num_map[summend[i]-'A']+'0');
        an.push_back(num_map[ans[i]-'A']+'0');
    }
    int over = 0;
    string res;
    for(int i = N-1;i>=0;i--){
        int a,b;
        a = add[i] - '0';
        b = summ[i] - '0';
        if(a+b+over>=N){
            res.insert(0,1,'0'+a+b+over-N);
            over = (a+b+over)/N;
        }else{
            res.insert(0,1,'0'+a+b+over);
            over = 0;
        }
    }
    if (over != 0){
        res.insert(0,1,'0'+over);
    }
    if(res==an){
        return true;
    }else{
        return false;
    }
}
void dfs(int ind){
    if(ind >= N){
        if(judge()){
            for(int i = 0;i<N;i++){
                cout<<num_map[i]<<" ";
            }
            cout<<endl;
            exit(0);
        }else{
            return ;
        }
    }
    for(int i = 0 ;i < N ; i++){
        if(!used[i]){
            used[i] = true;
            num_map[ind] = i;
            dfs(ind+1);
            used[i] = false;
        }
    }
}
int main(){
    for(int i = 0;i<=26;i++){
        num_map[i] = 0;
    }
    for(int i = 0;i<=13;i++){
        used[i] = false;
    }
    cin>>N>>addend>>summend>>ans;
    dfs(0);
    return 0;
}



