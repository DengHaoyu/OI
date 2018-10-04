////
//// Created by dhy on 18-8-20.
////
//#include <iostream>
//using namespace std;
//int sum[5010][5010];
//int R;
//inline int getArea(int x1,int y1,int x2,int y2){
//    if(x2<0)x2=0;
//    if(y2<0)y2=0;
//    int ans = sum[x1][y1]-sum[x1][y2]-sum[x2][y1]+sum[x2][y2];
//    return ans;
//}
//inline int max(int x,int y){return x>y?x:y;}
//int main(void){
//    ios::sync_with_stdio(false);
//    int n;
//    int tx,ty,vi;
//    cin>>n>>R;
//    int maxx = 0,maxy = 0;
//    for(int i = 1;i<=n;i++){
//        cin>>tx>>ty>>vi;
//        sum[tx][ty] = vi;
//        maxx = max(maxx,tx);
//        maxy = max(maxy,ty);
//    }
//    for(int i = 1;i<=maxx;i++){
//        sum[i][0] = sum[i-1][0]+sum[i][0];
//    }
//    for(int j = 1;j<=maxy;j++){
//        sum[0][j] = sum[0][j-1]+sum[0][j];
//    }
//    for(int i = 1;i<=maxx;i++){
//        for(int j = 1;j<=maxy;j++){
//            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
//        }
//    }
//    int ans = 0;
//    for(int i = 0;i<=maxx;i++){
//        for(int j = 0;j<=maxy;j++){
//            ans = max(ans,getArea(i,j,i-R,j-R));
//        }
//    }
//    cout<<ans;
//    return 0;
//}
//我已经放弃了，我想睡了，万不得已才抄题解
//OIers never give up!
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int n,r,dp[5101][5101];
void read(int &n)
{
    char c='+';int x=0;bool flag=0;
    while(c<'0'||c>'9'){c=getchar();if(c=='-')flag=1;}
    while(c>='0'&&c<='9')
    {x=x*10+c-48;c=getchar();}
    flag==1?n=-x:n=x;
}
int ans=0;
int main()
{
    read(n);read(r);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        read(x);read(y);read(z);
        dp[x+1][y+1]=z;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j];
    for(int i=0;i<=5001-r;i++)
        for(int j=0;j<=5001-r;j++)
            ans=max(ans,dp[i+r][j+r]-dp[i+r][j]-dp[i][j+r]+dp[i][j]);
    printf("%d",ans);
    return 0;
}