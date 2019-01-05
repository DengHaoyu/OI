#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int read(){
    int x = 0,f = 1;
    static char c = getchar();
    while(c<'0'||c>'9'){ if(c=='-')f = -1;c = getchar(); }
    while(c>='0'&&c<='9'){ x = (x<<1)+(x<<3)+(c^'0');c = getchar(); }
    return x*f;
}
const int MAXN = 1000010;
int nums[MAXN],id;
struct op{
    int opt,val,time,id;
    bool operator<(const op &op2)const {return val<op2.val;}
}ops[MAXN];
bool cmp(const op &op1,const op &op2){
    return op1.time<op2.time;
}
int cnt[MAXN];
int n;
void insert(int val){
    int id = val;
    cnt[id]++;
}
void del(int val){
    int id = val;
    if(cnt[id]>0)cnt[id]--;
}
int getRank(int val){
    int Id = val;
    int ans = 0;
    for(int i = 0;i<Id;i++)ans+=cnt[i];
    return ans+1;
}
int getVal(int rank){
    int ans = cnt[1];
    int pos = 1;
    while(ans<rank)
        ans+=cnt[++pos];
    return nums[pos];
}
int getPre(int val){
    int Id = val-1;
    while(Id>=1)if(cnt[Id]>0)return nums[Id];else Id--;
    return 2333;
}
int getBack(int val){
    int Id = val+1;
    while(Id<=id)if(cnt[Id]>0)return nums[Id];else Id++;
    return 23333;
}

int main(void){
    n = read();
    for(int i = 1;i<=n;i++)ops[i].opt = read(),ops[i].val = read(),ops[i].time = i;
    sort(ops+1,ops+n+1);
    ops[0].val = 0x7f7f7f7f;//
    id = 0;
    for(int i = 1;i<=n;i++){
        if(ops[i].val==ops[i-1].val)ops[i].id = ops[i-1].id;
        else nums[++id] = ops[i].val,ops[i].id = id;
    }
    int cnt = 0;
    sort(ops+1,ops+1+n,cmp);
    for(int i = 1;i<=n;i++){
        if(ops[i].opt==1){insert(ops[i].id);continue;}
        else if(ops[i].opt == 2){del(ops[i].id);continue;}
        else if(ops[i].opt == 3){printf("%d\n",getRank(ops[i].id));continue;}
        else if(ops[i].opt == 4){printf("%d\n",getVal(ops[i].val));continue;}
        else if(ops[i].opt == 5){printf("%d\n",getPre(ops[i].id));continue;}
        else printf("%d\n",getBack(ops[i].id));
    }
    return 0;
}