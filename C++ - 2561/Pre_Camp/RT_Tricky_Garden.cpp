/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,cl,cr;
};
A a[100010];
int dp[100010][25],finish[100010];
int n,k;
int dfs(int now,int k){
    if(finish[now])     return n;
    if(dp[now][k]!=-1)  return dp[now][k];
    int minn = 1e9;
    for(int i=0;i<=k;i++){
        minn = min(minn,min(dfs(a[now].l,i),a[now].cl)+min(dfs(a[now].r,k-i),a[now].cr));
    }
    if(k){
        minn = min(minn,min(a[now].cl,dfs(a[now].l,k-1)));
        minn = min(minn,min(a[now].cr,dfs(a[now].r,k-1)));
    }
    // printf("%d %d : %d\n",now,k,minn);
    return dp[now][k] = minn;
}
int main(){
    int m,opr;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",&opr);
        if(opr == 1)
            scanf("%d %d %d %d",&a[i].l,&a[i].r,&a[i].cl,&a[i].cr);
        else if(opr == 2)
            finish[i] = 1;
    }
    int minn = 1e9;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<=k;i++)
        minn = min(minn,dfs(1,i));
    printf("%d\n",min(minn,n));
    memset(finish,0,sizeof finish);
	return 0;
}
