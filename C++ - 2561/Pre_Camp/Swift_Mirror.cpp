/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[510][510],mark[510][510][4],traveling[510][510][4];
int n,m;
//dir 0 up 1 left 2 down 3 right
int dfs(int ni,int nj,int dir,int state){
    if(state>249999){
        while(1);
    }
    if(ni<1 || nj<1 || ni>n || nj>m)    return 0;
    if(a[ni][nj] == 'S')                return 0;
    if(traveling[ni][nj][dir])          return 1e9;
    if(mark[ni][nj][dir]!=-1)           return mark[ni][nj][dir];
    traveling[ni][nj][dir] = 1;
    if(a[ni][nj] == '/'){
        if(dir == 0)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj+1,3,state+1)+1);
        if(dir == 1)    mark[ni][nj][dir] = min((int )1e9,dfs(ni+1,nj,2,state+1)+1);
        if(dir == 2)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj-1,1,state+1)+1);
        if(dir == 3)    mark[ni][nj][dir] = min((int )1e9,dfs(ni-1,nj,0,state+1)+1);
    }else if(a[ni][nj] == '\\'){
        if(dir == 0)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj-1,1,state+1)+1);
        if(dir == 1)    mark[ni][nj][dir] = min((int )1e9,dfs(ni-1,nj,0,state+1)+1);
        if(dir == 2)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj+1,3,state+1)+1);
        if(dir == 3)    mark[ni][nj][dir] = min((int )1e9,dfs(ni+1,nj,2,state+1)+1);
    }else{
        if(dir == 0)    mark[ni][nj][dir] = min((int )1e9,dfs(ni-1,nj,0,state+1)+1);
        if(dir == 1)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj-1,1,state+1)+1);
        if(dir == 2)    mark[ni][nj][dir] = min((int )1e9,dfs(ni+1,nj,2,state+1)+1);
        if(dir == 3)    mark[ni][nj][dir] = min((int )1e9,dfs(ni,nj+1,3,state+1)+1);
    }
    traveling[ni][nj][dir] = 0;
    return mark[ni][nj][dir];
}
int main(){
    int sti,stj;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    scanf("%d %d",&sti,&stj);
    memset(mark,-1,sizeof mark);
    if(dfs(sti,stj,0,0) == 1e9)       printf("U\nInfinity\n");
    else if(dfs(sti,stj,3,0) == 1e9)  printf("R\nInfinity\n");
    else if(dfs(sti,stj,2,0) == 1e9)  printf("D\nInfinity\n");
    else if(dfs(sti,stj,1,0) == 1e9)  printf("L\nInfinity\n");
    else{
        int maxx = max(dfs(sti,stj,0,0),max(dfs(sti,stj,1,0),max(dfs(sti,stj,2,0),dfs(sti,stj,3,0))));
        if(maxx == dfs(sti,stj,0,0))      printf("U\n%d\n",maxx);
        else if(maxx == dfs(sti,stj,3,0)) printf("R\n%d\n",maxx);
        else if(maxx == dfs(sti,stj,2,0)) printf("D\n%d\n",maxx);
        else                            printf("L\n%d\n",maxx);
    }
	return 0;
}
