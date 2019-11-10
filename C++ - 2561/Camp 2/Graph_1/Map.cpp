/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int u[40010],d[40010],l[40010],r[40010],ans[410][410],temp,n,m,countt = 0;
void dfs(int now,int i,int j){
    countt++;
    if(countt == temp){
        for(int ii=1;ii<=400;ii++){
            for(int jj=1;jj<=400;jj++){
                if(ans[ii][jj] == -1)   continue;
                for(int k=ii;k<ii+n;k++){
                    for(int ll=jj;ll<jj+m;ll++)
                        printf("%d ",ans[k][ll]);
                    printf("\n");
                }
                exit(0);
            }
        }
    }
    if(u[now] != -1 && ans[i-1][j] == -1){
        ans[i-1][j] = u[now];
        dfs(u[now],i-1,j);
    }
    if(d[now] != -1 && ans[i+1][j] == -1){
        ans[i+1][j] = d[now];
        dfs(d[now],i+1,j);
    }
    if(l[now] != -1 && ans[i][j-1] == -1){
        ans[i][j-1] = l[now];
        dfs(l[now],i,j-1);
    }
    if(r[now] != -1 && ans[i][j+1] == -1){
        ans[i][j+1] = r[now];
        dfs(r[now],i,j+1);
    }
}
int main(){
    int a,b;
    char c;
    scanf("%d %d",&n,&m);
    temp = n*m;
    memset(u,-1,sizeof u);
    memset(d,-1,sizeof d);
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    for(int i=1;i<temp;i++){
        scanf("%d %c %d",&a,&c,&b);
        if(c == 'U'){
            u[b] = a;
            d[a] = b;
        }else{
            l[b] = a;
            r[a] = b;
        }
    }

    memset(ans,-1,sizeof ans);
    ans[200][200] = 0;
    dfs(0,200,200);
	return 0;
}
