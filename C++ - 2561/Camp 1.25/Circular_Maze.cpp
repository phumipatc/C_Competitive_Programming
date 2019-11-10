/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int r,c,mark[110][110],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
void dfs(int ni,int nj){
    if(a[ni][nj] == 'E'){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    int nexti,nextj;
    for(int k=0;k<4;k++){
        nexti = (ni+dir[0][k]+r)%r;
        nextj = (nj+dir[1][k]+c)%c;
        if(a[nexti][nextj] == '#')  continue;
        if(mark[nexti][nextj])      continue;
        char temp = a[nexti][nextj];
        mark[nexti][nextj] = 1;
        if(a[nexti][nextj] != 'E')
            a[nexti][nextj] = 'x';
        dfs(nexti,nextj);
        a[nexti][nextj] = temp;
    }
}
int main(){
    int sti,stj;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'S')  sti = i,stj = j;
        }
    }
    mark[sti][stj] = 1;
    dfs(sti,stj);
	return 0;
}
