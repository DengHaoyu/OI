//
// Created by dhy on 6/27/18.
//
#include <iostream>
#include <algorithm>
using namespace std;
struct competitor{
    int score;
    int ability;
    int id;
};
bool cmp(competitor c1,competitor c2){
    if(c1.score!=c2.score)return c1.score>c2.score;
    else return c1.id<c2.id;
}
int main(){
    int N,R,Q;
    cin>>N>>R>>Q;
    competitor *competitors = new competitor[2*N+1]();
    for(int i = 1;i<=2*N;i++){
        competitors[i].id = i;
        cin>>competitors[i].score;
    }
    for(int i = 1;i<=2*N;i++){
        cin>>competitors[i].ability;
    }
    sort(competitors+1,competitors+2*N+1,cmp);
    for(int j = 1;j<=R;j++) {
        for (int i = 1; i <= N; i++) {
            if (competitors[2 * i - 1].ability > competitors[2 * i].ability) {
                competitors[2 * i - 1].score++;
            }
            else {
                competitors[2 * i].score ++;
            }
        }
        sort(competitors+1,competitors+2*N+1,cmp);
    }
    cout<<competitors[Q].id;
    return 0;
}

