/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define USED 10000000000
using namespace std;
struct A{
    int i,j,w,use;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int a[110][110],dis[110][110][2],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int n,m,sti,stj,eni,enj,hr,mi,ni,nj;
    scanf("%d %d %d %d %d %d %d:%d",&n,&m,&sti,&stj,&eni,&enj,&hr,&mi);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dis[i][j][0] = dis[i][j][1] = 1e9;
        }
    }
    if(a[sti][stj]<0){
        dis[sti][stj][0] = 0;
        heap.push({sti,stj,0,0});
        dis[sti][stj][1] = a[sti][stj];
        heap.push({sti,stj,a[sti][stj],1});
    }else{
        dis[sti][stj][0] = a[sti][stj];
        heap.push({sti,stj,a[sti][stj],0});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        for(int k=0;k<4;k++){
            ni = now.i+dir[0][k];
            nj = now.j+dir[1][k];
            if(ni<1 || nj<1 || ni>n || nj>m)    continue;
            if(a[ni][nj]<0){
                if(now.use == 0){
                    if(dis[ni][nj][1]>now.w+a[ni][nj]){
                        dis[ni][nj][1] = now.w+a[ni][nj];
                        heap.push({ni,nj,dis[ni][nj][1],1});
                    }
                    if(dis[ni][nj][0]>now.w){
                        dis[ni][nj][0] = now.w;
                        heap.push({ni,nj,now.w,0});
                    }
                }else{
                    if(dis[ni][nj][1]>now.w){
                        dis[ni][nj][1] = now.w;
                        heap.push({ni,nj,now.w,1});
                    }
                }
            }else{
                if(dis[ni][nj][now.use]>now.w+a[ni][nj]){
                    dis[ni][nj][now.use] = now.w+a[ni][nj];
                    heap.push({ni,nj,dis[ni][nj][now.use],now.use});
                }
            }
        }
    }
    mi+=min(dis[eni][enj][0],dis[eni][enj][1]);
    hr+=floor((double)mi/60);
    mi = ((mi%60)+60)%60;
    hr = ((hr%12)+12)%12;
    printf("%02d:%02d\n",hr,mi);
	return 0;
}
