#include<bits/stdc++.h>
using namespace std;
#define maxn 25
#define maxk 150
int dp[maxn][maxk][1024];
bool crash[1024][1024];
void pre(int n)
{
    for(int i=0;i<=(1<<n)-1;i++)
        for(int j=0;j<=(1<<n)-1;j++)
            if((i&j)||((i<<1)&j)||((j<<1)&i)||((j>>1)&i)||((i>>1)&j)) crash[i][j]=crash[j][i]=true;
    return;
}
int sum(int m)
{
    int tot=0;
    while(m)
    {
        if(m&1)	tot++;
        m>>=1;
    }
    return tot;
}
/*void out(int n,int a)
{
    cout<<"行数	至此以前已经	当前的状态	总共"<<endl;
    for(int i=1;i<=n;i++)//枚举多少行 
        for(int k=0;k<=a;k++)
            for(int j=0;j<=(1<<n)-1;j++)//枚举当前行的状态 
                if(dp[i][k][j]){
                    cout<<i<<"	"<<k<<" "<<j<<"		"<<dp[i][k][j]<<endl;
                }
}*/
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    pre(n);
    //dp[1][1][0]=1;
    for(int i=0;i<=(1<<n)-1;i++)
        if(!(i&(i<<1)))
            dp[1][sum(i)][i]=1;
    /*for(int i=1;i<=(1<<n)-1;i++)
        if(dp[1][sum(i)][i])cout<<i<<" ";*/
    for(int i=2;i<=n;i++)//枚举多少行 
        for(int j=0;j<=(1<<n)-1;j++)//枚举当前行的状态 
            for(int v=0;v<=(1<<n)-1;v++)//枚举上一行的状态 
            {
                if(crash[j][v]) continue;
                if((j<<1)&j||(j>>1)&j||(v<<1)&v||(v>>1)&v) continue;
                int tmp=sum(j);
                for(int mid=0;mid<=k;mid++) dp[i][tmp+mid][j]+=dp[i-1][mid][v];
                //dp[i+1][mid][j]+=dp[i][mid-tmp][v];
            }
    //out(n,k);
    long long ans=0;
    for(int i=0;i<=(1<<n)-1;i++) ans+=dp[n][k][i];
    cout<<ans<<endl;
    return 0;
} 