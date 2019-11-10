/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int n,m,minn = 1e9;
void dfs(int i,int j,int sum){
    if(i == n+1){
        minn = min(minn,sum);
        return ;
    }
    if(j>1) dfs(i+1,j-1,sum+a[i][j]);
    if(j<m) dfs(i+1,j+1,sum+a[i][j]);
    dfs(i+1,j,sum+a[i][j]);
}
int main(){
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin >> a[i][j];
    for(int j=1;j<=m;j++){
        dfs(1,j,0);
    }
    printf("%d\n",minn);
	return 0;
}