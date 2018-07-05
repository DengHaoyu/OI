//
// Created by dhy on 6/24/18.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct volunteer{
    int id;
    int score;
};
bool sor(volunteer v1,volunteer v2){
    if(v1.score==v2.score){
        return v1.id<v2.id;
    }
        return v1.score>v2.score;
}
int main(){
    int m,n;
    cin>>n>>m;
    vector<volunteer> vols;
    for(int i = 0;i<n;i++){
        volunteer v;
        cin>>v.id>>v.score;
        vols.push_back(v);
    }
    sort(vols.begin(),vols.end()+1,sor);
    int line = vols[m*1.5-1].score;
    int count = 0;
    for(int i = 0;i<n;i++){
        if(vols[i].score>=line)count++;
    }
    cout<<line<<" "<<count<<endl;
    for(int i = 0;i<count;i++){
        cout<<vols[i].id<<" "<<vols[i].score<<endl;
    }
    return 0;
}