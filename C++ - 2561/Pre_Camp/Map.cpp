/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[410][410],U[40010],D[40010],L[40010],R[40010];
void dfs(int i,int j,int now){
    a[i][j] = now;
    // printf("%d %d %d\n",i,j,now);
    if(U[now]!=-1 && a[i-1][j] == -1)   dfs(i-1,j,U[now]);
    if(D[now]!=-1 && a[i+1][j] == -1)   dfs(i+1,j,D[now]);
    if(L[now]!=-1 && a[i][j-1] == -1)   dfs(i,j-1,L[now]);
    if(R[now]!=-1 && a[i][j+1] == -1)   dfs(i,j+1,R[now]);
}
int main(){
    int n,m,u,v;
    char opr;
    memset(U,-1,sizeof U);
    memset(D,-1,sizeof D);
    memset(L,-1,sizeof L);
    memset(R,-1,sizeof R);
    scanf("%d %d",&n,&m);
    for(int i=1;i<n*m;i++){
        scanf("%d %c %d",&u,&opr,&v);
        if(opr == 'U'){
            U[v] = u;
            D[u] = v;
        }else{
            L[v] = u;
            R[u] = v;
        }
    }
    memset(a,-1,sizeof a);
    dfs(n,m,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == -1)   continue;
            for(int k=i;k<i+n;k++){
                for(int l=j;l<j+m;l++){
                    printf("%d ",a[k][l]);
                }
                printf("\n");
            }
            return 0;
        }
    }
	return 0;
}
