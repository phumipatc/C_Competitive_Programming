/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[1010];
double px[1010],py[1010],d[1010][1010],dist[1010];
int main()
{
    int n,w,r,s,i,j;
    double m;
    scanf("%d %d %lf",&n,&w,&m);
    for(i=0;i<n;i++)
        scanf("%lf %lf",&px[i],&py[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j]=sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
    while(w--){
        scanf("%d %d",&r,&s);
        r--,s--;
        d[r][s]=d[s][r]=0;
    }
    for(i=0;i<n;i++)
        dist[i]=-1;
    dist[0]=0;
    while(!mark[n-1]){
        int x=-1;
        for(i=0;i<n;i++){
            if(!mark[i] && dist[i]>=0 && (x==-1 || dist[i]<dist[x]))
                x=i;
        }
        if(x==-1)   break;
        mark[x]=1;
        for(i=0;i<n;i++){
            if(!mark[i] &&d[x][i]<=m && (dist[i]==-1 || dist[x]+d[x][i]<dist[i]))
                dist[i]=dist[x]+d[x][i];
        }
    }
    if(!mark[n-1])  printf("-1\n");
    else            printf("%d\n",(int)(dist[n-1]*1000));
    return 0;
}
/*
9 3
2.0
0 0
0 1
1 1
2 1
2 2
3 2
3 3
4 1
4 3
1 2
2 3
3 4
*/
