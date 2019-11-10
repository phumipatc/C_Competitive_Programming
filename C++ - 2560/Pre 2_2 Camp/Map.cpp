/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int m,n,l[40100],u[40100],r[40100],d[40100],table[1100][1100];
void dfs(int now,int i,int j){
//    printf("%d %d %d\n",now,i,j);
    table[i][j]=now;
    if(r[now]!=table[i][j+1] && r[now]!=-1)
        dfs(r[now],i,j+1);
    if(l[now]!=table[i][j-1] && l[now]!=-1)
        dfs(l[now],i,j-1);
    if(d[now]!=table[i+1][j] && d[now]!=-1)
        dfs(d[now],i+1,j);
    if(u[now]!=table[i-1][j] && u[now]!=-1)
        dfs(u[now],i-1,j);
}
int main(){
    int i,j,a,b;
    char pos;
    memset(d,-1,sizeof d);
    memset(r,-1,sizeof r);
    memset(u,-1,sizeof u);
    memset(l,-1,sizeof l);
    scanf("%d %d",&m,&n);
    for(i=1;i<m*n;i++){
        scanf("%d %c %d",&a,&pos,&b);
        if(pos=='U'){
            d[a]=b;
            u[b]=a;
        }else{
            r[a]=b;
            l[b]=a;
        }
    }
    memset(table,-1,sizeof table);
    dfs(0,250,250);
    for(i=1;i<=500;i++){
        for(j=1;j<=500;j++){
            if(table[i][j]!=-1)
                goto next;
        }
    }
    next:;
    int ii=i,jj=j;
    for(i=ii;i<=ii+m-1;i++){
        for(j=jj;j<=jj+n-1;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
    return 0;
}
