/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mapp[405][405];
int l[40005],r[40005],u[40005],d[40005];
void dfs(int now,int i,int j){
    mapp[i][j] = now;
    if(l[now]!=-1 && mapp[i][j-1] == -1)    dfs(l[now],i,j-1);
    if(r[now]!=-1 && mapp[i][j+1] == -1)    dfs(r[now],i,j+1);
    if(u[now]!=-1 && mapp[i-1][j] == -1)    dfs(u[now],i-1,j);
    if(d[now]!=-1 && mapp[i+1][j] == -1)    dfs(d[now],i+1,j);
}
int main(){
    int m,n,a,b,i,j,k,x;
    char opr;
    scanf("%d %d",&m,&n);
    memset(mapp,-1,sizeof mapp);
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    memset(u,-1,sizeof u);
    memset(d,-1,sizeof d);
    for(i=1;i<(m*n);i++){
        scanf("%d %c %d",&a,&opr,&b);
        if(opr == 'U')  u[b] = a,d[a] = b;
        else            l[b] = a,r[a] = b;
    }
    dfs(0,m,n);
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(mapp[i][j]!=-1){
                for(k=i;k<(i+m);k++){
                    for(x=j;x<(j+n);x++)
                        printf("%d ",mapp[k][x]);
                    printf("\n");
                }
                return 0;
            }
        }
    }
    return 0;
}
