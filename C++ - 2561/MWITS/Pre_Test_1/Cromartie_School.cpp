/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j;
};
vector<A > v;
char a[70][70];
int n,m,dp[70][70],mark[70][70],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
void dfs(int i,int j){
    mark[i][j] = 1;
    for(int k=0;k<4;k++){
        int ni = i+dir[0][k],nj = j+dir[1][k];
        if(ni<1 || nj<1 || ni>n || nj>m)    continue;
        if(mark[ni][nj])                    continue;
        if(a[ni][nj] != 'P')                continue;
        dfs(ni,nj);
    }
}
int main(){
    int ans = 0;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 'T')  continue;
            dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            if(dp[i][j]>ans){
                ans = dp[i][j];
                v.clear();
                v.push_back({i,j});
            }else if(dp[i][j] == ans){
                v.push_back({i,j});
            }
        }
    }
    int ans2 = 1e9,countt;
    for(auto x:v){
        memset(mark,0,sizeof mark);
        countt = 0;
        for(int i=x.i-ans+1;i<=x.i;i++){
            for(int j=x.j-ans+1;j<=x.j;j++){
                if(a[i][j] == 'S')  continue;
                if(mark[i][j])      continue;
                dfs(i,j);
                countt++;
            }
        }
        ans2 = min(ans2,countt);
    }
    printf("%d %d\n",ans*ans,ans2);
	return 0;
}
/*
6 5
TSSSSS
TTSSSS
SSSPSS
SSPPPS
TSSPST
*/