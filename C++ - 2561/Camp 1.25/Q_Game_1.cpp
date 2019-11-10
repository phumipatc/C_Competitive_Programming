/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
queue<pair<int,int> > a,b;
pair<int,int> p;
int tab[1000][1000],ma[550][550],mb[550][550],dir[2] = {0,-1},dic[2] = {1,0};
int main()
{
    int r,c,i,j,A,B,nextx,nexty,ch = 1;
    long long sum = 0;
    scanf(" %d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %d",&tab[i][j]);
    a.push(make_pair(0,r-1));
    b.push(make_pair(0,r-1));
    while(!a.empty() && !b.empty()){
        A=a.size();
        B=b.size();
        sum+=A*B;
        for(i=0;i<A;i++){
            for(j=0;j<2;j++){
                nextx=a.front().first+dic[j];
                nexty=a.front().second+dir[j];
                if(nextx<0||nextx>=c||nexty<0||nexty>=r) continue;
                if(tab[nexty][nextx] || ma[nexty][nextx]) continue;
                ma[nexty][nextx]=1;
                a.push(make_pair(nextx,nexty));
            }
            a.pop();
        }
        for(i=0;i<B;i++){
            for(j=0;j<2;j++){
                nextx=b.front().first+dic[j];
                nexty=b.front().second+dir[j];
                if(nextx<0||nextx>=c||nexty<0||nexty>=r) continue;
                if(tab[nexty][nextx]  || mb[nexty][nextx]) continue;
                mb[nexty][nextx]=1;
                b.push(make_pair(nextx,nexty));
            }
            b.pop();
        }
//        printf("%d %d\n",(int)a.size(),(int)b.size());
    }
    printf("%lld",sum);
    return 0;
}
