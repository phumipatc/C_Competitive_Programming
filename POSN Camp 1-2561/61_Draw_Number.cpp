/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[6][6],mark[1000010],ans,dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
void draw(int i,int j,int state,int sum){
    if(state == 5){
        if(mark[sum])   return ;
        mark[sum] = 1;
        ans++;
        return ;
    }
    for(int k=0;k<4;k++){
        int ni = i+dir[0][k];
        int nj = j+dir[1][k];
        if(ni<1 || nj<1 || ni>5 || nj>5)    continue;
        draw(ni,nj,state+1,sum*10+a[ni][nj]);
    }
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                draw(i,j,0,a[i][j]);
        printf("%d\n",ans);
        memset(mark,0,sizeof mark);
    }
	return 0;
}