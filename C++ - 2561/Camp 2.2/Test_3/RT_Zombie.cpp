/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i,j,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
int dis[1001][1001],a[1001][1001],dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
priority_queue< A> heap;
int main(){
    int r,c,k,nexti,nextj;
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[i][j]),dis[i][j] = 1e9;
    for(int i=1;i<k;i++)    heap.push({i,1,a[i][1]}),dis[i][1] = a[i][1];
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.j == 1 && now.i>k){
            printf("%d\n",dis[now.i][now.j]);
            return 0;
        }
        for(int i=0;i<4;i++){
            nexti = now.i+dir[0][i];
            nextj = now.j+dir[1][i];
            if(nexti == k && nextj == 1)    continue;
            if(dis[nexti][nextj]>now.w+a[nexti][nextj]){
                dis[nexti][nextj] = now.w+a[nexti][nextj];
                heap.push({nexti,nextj,dis[nexti][nextj]});
            }
        }
    }
    return 0;
}
