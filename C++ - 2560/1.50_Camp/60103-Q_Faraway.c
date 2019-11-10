/*
    TASK : Q_Far far away
    AUTHOR : Tanapoon Laoaroon
    SCHOOL : RYW
    LANG : CPP
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
struct A{
    int target,path;
};
A temp,peat[100100];
int dist[100100];
int main()
{
    int n,m,q,i,j;
    int a,b,c;
    scanf(" %d",&q);
    while(q--){
        scanf(" %d %d",&n,&m);
        for(i=0;i<n-1;i++){
            scanf(" %d %d %d",&a,&b,&c);
            temp.target=a-1;
            temp.path=c;
            peat[b-1]=temp;
        }
        for(i=n-1;i>=1;i--){
            if(dist[i]+peat[i].path>dist[peat[i].target]) dist[peat[i].target]=dist[i]+peat[i].path;
        }
        if(dist[0]>=m) printf("%d\n",dist[0]);
        else printf("-1\n");
        memset(dist,0,sizeof dist);

    }
    return 0;
}
