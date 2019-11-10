/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w,type;
};
A now;
queue< A> que;
char a[55][55];
int dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int main(){
    int r,c,sti,stj,eni,enj,ni,nj;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == 'S')      sti = i,stj = j;
            else if(a[i][j] == 'D') eni = i,enj = j;
            else if(a[i][j] == '*') que.push({i,j,0,1});
        }
    }
    que.push({sti,stj,0,0});
    while(!que.empty()){
        now = que.front();
        que.pop();
        if(now.type == 0 && now.i == eni && now.j == enj){
            printf("%d\n",now.w);
            return 0;
        }
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k],nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>r || nj>c)        continue;
            if(a[ni][nj]!='.' && a[ni][nj] != 'D')  continue;
            if(a[ni][nj] == 'D' && now.type == 1)   continue;
            a[ni][nj] = '*';
            que.push({ni,nj,now.w+1,now.type});
        }
    }
    printf("KAKTUS\n");
	return 0;
}
