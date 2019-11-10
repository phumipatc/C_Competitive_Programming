/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
int dis[60][60];
int change(char c){
    if(isupper(c))  return c-'A';
    else            return c-'a'+26;
}
int main()
{
    int i,j,dist,r,s,minn=INF,p,k;
    char a,b,ans='A';
    for(i=0;i<52;i++)
        for(j=0;j<52;j++)
            if(i==j)    dis[i][j]=0;
            else        dis[i][j]=INF;
    scanf("%d",&p);
    while(p--){
        scanf(" %c %c %d",&a,&b,&dist);
        r=change(a);
        s=change(b);
        if(dist<dis[r][s])  dis[r][s]=dist;
        if(dist<dis[s][r])  dis[s][r]=dist;
    }
    for(k=0;k<52;k++)
        for(i=0;i<52;i++)
            for(j=0;j<52;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(i=0;i<25;i++){
        if(dis[i][25]<minn)
            minn=dis[i][25],ans=i+'A';
    }
    printf("%c %d\n",ans,minn);
    return 0;
}
/*
5
A d 6
B d 3
C e 9
d Z 8
e Z 3
*/
