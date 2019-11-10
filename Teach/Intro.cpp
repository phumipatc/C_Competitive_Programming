/*
    AUTHOR: Magnam Caritatem
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[7][7],ans[7],mark[1000005];
int dir[4] = {-1,1,0,0},dic[4] = {0,0,1,-1};
int countt = 0;
void draw(int i,int j,int state){
    ans[state] = a[i][j];
    if(state == 6){
        int sum = 0;
        for(int k=1;k<=6;k++){
            sum*=10;
            sum+=ans[k];
        }
        if(!mark[sum])  countt++;
        mark[sum] = 1;
        return ;
    }
    for(int k=0;k<4;k++){
        int ii = i+dir[k],jj = j+dic[k];
        if(ii == 0 || jj == 0 || ii>5 || jj>5)  continue;
        draw(ii,jj,state+1);
    }
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        countt = 0;
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=5;i++)
            for(int j=1;j<=5;j++)
                draw(i,j,1);
        printf("%d\n",countt);
        for(int i=0;i<=999999;i++)
            mark[i] = 0;
    }
	return 0;
}
