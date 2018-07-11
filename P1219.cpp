//
// Created by dhy on 18-7-7.
//

//O2 AC
#include <iostream>
#include <cmath>
using namespace std;
int x_of_queen[14] = {0};
int count = 0;
int N;
void print(){
    if(count<=3){
        for(int i = 1;i<=N;i++){
            cout<<x_of_queen[i]<<' ';
        }
        cout<<endl;
    }
}
void search(int ind){
    if(ind>N){
        count++;
        print();
        return;
    }

    for(int i = 1;i<=N;i++){
        if(ind == 1){
            x_of_queen[ind] = i;
            search(ind+1);
        }else{
            bool can_put_here = true;
            for(int j = 1;j<ind;j++){
                if(i==x_of_queen[j]||abs(ind-j)==abs(i-x_of_queen[j])){
                    can_put_here = false;
                    break;
                }
            }
            if(can_put_here){
                x_of_queen[ind] = i;
                search(ind+1);
            }
        }
    }
}
int main(){
    cin>>N;
    search(1);
    cout<<count;
    return 0;
}