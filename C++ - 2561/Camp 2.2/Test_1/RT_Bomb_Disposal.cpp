/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int v,w,bit,target;
	bool operator < (const A&o) const{
		if(w!=o.w)					return w>o.w;
		else if(target!=o.target)	return target<o.target;
		else if(v!=o.v)				return v>o.v;
		else						return bit>o.bit;
	}
};
A now;
priority_queue<A > heap;
int a[20],dis[20][20][33000];
int main(){
	int q,n,p,countt;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&p);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			a[i]--;
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=(1<<n);k++)
					dis[i][j][k] = 1e9;
		for(int i=0;i<n;i++){
			if(a[i]){
				dis[i][0][0] = dis[i][0][1<<a[i]] = 0;
				heap.push({i,0,0,0});
				if(p)
					heap.push({i,0,1<<a[i],0});
			}else{
				dis[i][0][0] = dis[i][1][0] = 0;
				heap.push({i,0,0,1});
			}
		}
		while(!heap.empty()){
			now = heap.top();
			heap.pop();
			// printf("%d %d %d %d\n",now.v,now.w,now.bit,now.target);
			if(now.target == n){
				printf("%d\n",now.w);
				break;
			}
			if(now.v-1>=0){
				countt = 0;
				for(int i=0;i<n;i++){
					if((now.bit|(1<<a[now.v-1])) & (1<<i))
						countt++;
				}
				if(a[now.v-1] == now.target){
					if(dis[now.v-1][now.target+1][now.bit]>now.w+1){
						dis[now.v-1][now.target+1][now.bit] = now.w+1;
						heap.push({now.v-1,now.w+1,now.bit,now.target+1});
					}
				}else{
					if(dis[now.v-1][now.target][now.bit]>now.w+1){
						dis[now.v-1][now.target][now.bit] = now.w+1;
						heap.push({now.v-1,now.w+1,now.bit,now.target});
					}
					if(dis[now.v-1][now.target][now.bit|(1<<a[now.v-1])]>now.w+1 && countt<=p && a[now.v-1]>=now.target){
						dis[now.v-1][now.target][now.bit|(1<<a[now.v-1])] = now.w+1;
						heap.push({now.v-1,now.w+1,now.bit|(1<<a[now.v-1]),now.target});
					}
				}
			}
			if(now.v+1<n){
				countt = 0;
				for(int i=0;i<n;i++){
					if((now.bit|(1<<a[now.v+1])) & (1<<i))
						countt++;
				}
				if(a[now.v+1] == now.target){
					if(dis[now.v+1][now.target+1][now.bit]>now.w+1){
						dis[now.v+1][now.target+1][now.bit] = now.w+1;
						heap.push({now.v+1,now.w+1,now.bit,now.target+1});
					}
				}else{
					if(dis[now.v+1][now.target][now.bit]>now.w+1){
						dis[now.v+1][now.target][now.bit] = now.w+1;
						heap.push({now.v+1,now.w+1,now.bit,now.target});
					}
					if(dis[now.v+1][now.target][now.bit|(1<<a[now.v+1])]>now.w+1 && countt<=p && a[now.v+1]>=now.target){
						dis[now.v+1][now.target][now.bit|(1<<a[now.v+1])] = now.w+1;
						heap.push({now.v+1,now.w+1,now.bit|(1<<a[now.v+1]),now.target});
					}
				}
			}
			while(now.bit&(1<<now.target)){
				now.bit^=(1<<now.target);
				if(dis[now.v][now.target+1][now.bit]>now.w){
					dis[now.v][now.target+1][now.bit] = now.w;
					heap.push({now.v,now.w,now.bit,now.target+1});
				}
				now.target++;
			}
		}
		while(!heap.empty())	heap.pop();
	}
    return 0;
}
