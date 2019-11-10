/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,d;
};
int cost[2100][210],dis[2100][210];
queue< A> q;
int main()
{
    int r,c,i,j,d,x,y,sti,stj,eni,enj,nexti,nextj,ans=0,k;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&cost[i][j]);
    scanf("%d",&d);
    d--;
    scanf("%d %d",&eni,&enj);
    int ch=1;
    while(d--){
        scanf("%d %d",&x,&y);
        memset(dis,0,sizeof dis);
        if(ch==1){
            eni=x,enj=y;
            ch=0;
        }else if(ch==0){
            sti=eni,stj,enj;
            eni=x,enj=y;
        }
        q.push({sti,stj,0});
        while(!q.empty()){
            A temp=q.front();
            q.pop();

        }
    }
    return 0;
}
