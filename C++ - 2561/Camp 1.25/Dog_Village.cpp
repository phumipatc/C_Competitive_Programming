/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,v;
};
A now;
queue< A> que;
int a[1010][1010],mark[1010][1010],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int main(){
    int n,m,ni,nj;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j])    mark[i][j] = 1,que.push({i,j,0});
        }
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(mark[ni][nj])        continue;
            if(now.v+1>=a[ni][nj])  continue;
            mark[ni][nj] = 1;
            que.push({ni,nj,now.v+1});
        }
    }
    int countt = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mark[i][j])  continue;
            countt++;
        }
    }
    printf("%d\n",countt);
	return 0;
}
