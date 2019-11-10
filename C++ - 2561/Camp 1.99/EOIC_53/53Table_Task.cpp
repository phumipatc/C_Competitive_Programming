/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define USED 10000000000
using namespace std;
struct A{
    int i,j,w,ch;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int a[110][110],dis[110][110],dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int n,m,sti,stj,eni,enj,hr,mi,ii,jj;
    scanf("%d %d %d %d %d %d %d:%d",&n,&m,&sti,&stj,&eni,&enj,&hr,&mi);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            dis[i][j] = 1e9;
        }
    }
    dis[sti][stj] = a[sti][stj];
    heap.push({sti,stj,dis[sti][stj],0});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.i == eni && now.j == enj){
            mi+=(dis[eni][enj]%60);
            hr+=(dis[eni][enj]/60)+(int )floor((double)mi/60);
            mi+=60,mi%=60;
            hr+=12,hr%=12;
            printf("%d:%d\n",hr,mi);
            break;
        }
        for(int k=0;k<4;k++){
            ii = now.i+dir[0][k];
            jj = now.j+dir[1][k];
            if(ii<1 || jj<1 || ii>n || jj>m)    continue;
            if(a[ii][jj]<0 && now.ch == 0){
                if(dis[ii][jj]>now.w+a[ii][jj]){
                    dis[ii][jj] = now.w+a[ii][jj];
                    heap.push({ii,jj,dis[ii][jj],1});
                }
            }else if(a[ii][jj]>0){
                if(dis[ii][jj]>now.w+a[ii][jj]){
                    dis[ii][jj] = now.w+a[ii][jj];
                    heap.push({ii,jj,dis[ii][jj],now.ch});
                }
            }else{
                if(dis[ii][jj]<now.w){
                    dis[ii][jj] = now.w;
                    heap.push({ii,jj,dis[ii][jj],now.ch});
                }
            }
        }
    }
	return 0;
}
