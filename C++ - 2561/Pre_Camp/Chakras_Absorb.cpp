/*
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
priority_queue<A > heap;
int dis[1010][1010],a[1010][1010],dir[2][4] = {{-1,1,0,0},{0,0,-1,1}};
int main(){
    int n,ch = 0,sti,stj,eni,enj,ni,nj;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j] == 0 && ch == 0){
                sti = i,stj = j;
                ch++;
            }else if(a[i][j] == 0){
                eni = i,enj = j;
            }
        }
    }
    memset(dis,127,sizeof dis);
    dis[sti][stj] = 0;
    heap.push({sti,stj,0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.i == eni && now.j == enj){
            printf("%d\n",dis[eni][enj]);
            break;
        }
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>n)        continue;
            if(dis[ni][nj]<=max(now.w,a[ni][nj]))   continue;
            dis[ni][nj] = max(now.w,a[ni][nj]);
            heap.push({ni,nj,dis[ni][nj]});
        }
    }
	return 0;
}
