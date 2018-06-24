//
// Created by dhy on 18-4-30.
//
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct peanut{
    int pieces = 0;
    int x;
    int y;
};
bool so(peanut a,peanut b){
    return a.pieces>b.pieces;
}
vector<peanut> peanuts;
int main(){
    int M,N,K;
    cin>>M>>N>>K;
    int p;
    for(int i = 1;i<=M;i++)
        for(int j = 1;j<=N;j++){
            cin>>p;
            if(p!=0){
                struct peanut pa;
                pa.pieces  = p;
                pa.x = i;
                pa.y = j;
                peanuts.push_back(pa);
            }
        }
    sort(peanuts.begin(),peanuts.end(),so);
    int gain = 0;
    int curr_time = 1;//this is important , because it takes 1 to go to the field from the road
    curr_time+=peanuts[0].x;
    gain+=peanuts[0].pieces;
    int i;
    for(i  = 1;i<peanuts.size()-1;i++){
        if((curr_time+=abs(peanuts[i].x-peanuts[i-1].x+peanuts[i].y-peanuts[i-1].y))<=
                K-1-peanuts[i+1].x){
            gain+=peanuts[i].pieces;
        }else{
            break;
        }
    }
    cout<<gain;

    return 0;
}