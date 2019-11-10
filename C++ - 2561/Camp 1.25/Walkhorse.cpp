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
queue< A> now;
char a[1010][1010];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    scanf("%d %d %d %d",&sti,&stj,&eni,&enj);
    if(a[sti][stj] == 'X' || a[eni][enj] == 'X'){
        printf("-1\n");
        return 0;
    }
    a[sti][stj] = 'X';
    que.push({sti,stj,0});
    while(!que.empty()){
        now = que.front();
        que.pop();
        for(int k=0;k<8;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
        }
    }
	return 0;
}
