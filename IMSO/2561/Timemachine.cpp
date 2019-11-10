/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int x,y,w,bit;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue< A> heap;
A a[12],now;
int dis[12][3000];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,k,x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
	a[k].x = n-1,a[k].y = m-1;
	for(int i=0;i<=k;i++)
		for(int j=0;j<=(1<<(k+1));j++)
			dis[i][j] = 1e9;
	heap.push({0,0,0,0});
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		// printf("now : %d %d %d %d\n",now.x,now.y,now.w,now.bit);
		for(int i=0;i<=k;i++){
			x = (a[i].x-now.x)*(a[i].x-now.x);
			y = (a[i].y-now.y)*(a[i].y-now.y);
			if((now.bit&(1<<i)) == (1<<i)){
				if(dis[i][now.bit]>now.w+ceil(sqrt(x+y))){
					dis[i][now.bit] = now.w+ceil(sqrt(x+y));
					heap.push({a[i].x,a[i].y,dis[i][now.bit],now.bit});
					// printf("next : %d %d %d %d %d\n",i,x,y,now.bit,dis[i][now.bit]);
				}
				continue;
			}
			if(dis[i][now.bit|(1<<i)]>now.w+ceil(sqrt(x+y))-a[i].w){
				dis[i][now.bit|(1<<i)] = now.w+ceil(sqrt(x+y))-a[i].w;
				heap.push({a[i].x,a[i].y,dis[i][now.bit|(1<<i)],now.bit|(1<<i)});
				// printf("next : %d %d %d %d %d\n",i,x,y,now.bit|(1<<k),dis[i][now.bit|(1<<i)]);
			}
		}
	}
	int minn = 1e9;
	for(int i=0;i<=(1<<(k+1));i++)
		minn = min(minn,dis[k][i]);
	printf("%d\n",minn);
	return 0;
}
