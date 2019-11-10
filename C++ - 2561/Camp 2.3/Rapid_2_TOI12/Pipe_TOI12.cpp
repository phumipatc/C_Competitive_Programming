/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A pos[15010];
int dis[15010];
int dist(int i,int j){
    return abs(pos[i].x-pos[j].x)+abs(pos[i].y-pos[j].y);
}
int main(){
    int n,k,minn,idx,sum = 0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&pos[i].x,&pos[i].y);
        dis[i] = 1e9;
    }
    for(int i=1;i<n;i++){
        minn = 1e9; 
        for(int j=i+1;j<=n;j++){
            dis[j] = min(dis[j],dist(i,j));
            if(minn>dis[j]){
                minn = dis[j];
                idx = j;
            }
        }
        swap(dis[i+1],dis[idx]);
        swap(pos[i+1],pos[idx]);
    }
    sort(dis+1,dis+n+1);
    for(int i=1;i<=n-k;i++)
        sum+=dis[i];
    printf("%d",sum);
	return 0;
}
