/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[310][5100],b[310];
int main()
{
    int r,c,m,k,i,j,v,x,y,minn;
    scanf("%d %d %d",&r,&c,&m);
    for(i=1;i<=m;i++){
        scanf("%d",&k);
        if(k==1){
            scanf("%d %d %d",&x,&y,&v);
            a[x][y]=v;
            for(j=1,b[x]=1e9;j<=c;j++)  b[x]=min(b[x],a[x][j]);
        }else if(k==2){
            scanf("%d %d",&x,&v);
            for(j=1;j<=c;j++)   a[x][j]=v;
            b[x]=v;
        }else if(k==3){
            scanf("%d %d",&x,&y);
            printf("%d\n",a[x][y]);
        }else if(k==4){
            for(j=1,minn=1e9;j<=r;j++)  minn=min(minn,b[j]);
            printf("%d\n",minn);
        }
    }
    return 0;
}
