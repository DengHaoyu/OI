#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int n;
int w[21];
int map[21][21];
long long b, s;
struct node {
    int d[21], ans;
    node(){
    }
    node(node &no) {
        for (int i = 1; i <= n; i++)d[i] = no.d[i];
    }
    void init(){
        for (int i = 1; i <= n; i++)d[i] = i;
    }
    void work() {
        int a = 0,p = d[1];
        for (int i = 2; i <= n; i++) {
            if(map[p][d[i]]==1){
                a+=w[d[i]];
                p = d[i];
            }
        }
        ans = a;
    }

};
node best;
double percent = 0.987;
const double org_T = 59260;
double ep = 0.0001;
void sa() {
    double curr_T = org_T;
    while (curr_T > ep) {
        node curr_ans(best);
        int x = (rand() % n)+1;
        int y = (rand() % n)+1;
        while (x == y) {
            x = (rand() % n) + 1;
            y = (rand() % n) + 1;
        }
        swap(curr_ans.d[x],curr_ans.d[y]);
        curr_ans.work();
        int delta = curr_ans.ans - best.ans;
        if (delta >= 0) {
            best = curr_ans;
        }else if(exp(-delta/curr_T)*RAND_MAX>rand()){
            best = curr_ans;
        }
        curr_T*=percent;
    }
}
void SA() {
    best.init();
    best.work();
    while(double(clock()-s)/double (CLOCKS_PER_SEC)<=0.8)sa();
}
int main(){
    cin>>n;
    int t;
    s = clock();
    srand(clock());
    for(int i = 1;i<=n;i++)cin>>w[i];
    for(int i = n;i>=1;i--)
        for(int j = 1;j<i;j++){
            cin>>t;
            map[i][j] = t;
            map[j][i] = t;
        }
    SA();
    int a = 0,p = best.d[1];
    for (int i = 2; i <= n; i++) {
        if(map[p][best.d[i]]==1){
            a+=w[best.d[i]];
            p = best.d[i];
            cout<<p<<' ';
        }
    }
    cout<<endl;
    cout<<best.ans;
    return 0;
}