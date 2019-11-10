/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
map<int ,int > mapp;
pair<int ,int > p[1010],pos;
int dist(pair<int ,int > a,pair<int ,int > b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main(){
    int n,m,minn,maxx = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&pos.x,&pos.y);
        minn = 1e9;
        for(int j=1;j<=n;j++)
            minn = min(minn,dist(pos,p[j]));
        mapp[minn]++;
        maxx = max(maxx,mapp[minn]);
    }
    printf("%d\n",maxx);
	return 0;
}