/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: MST[Prim]
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
struct A{
	int x,y;
};
A coor[15010];
int find_dis(A a,A b){
	return abs(a.x-b.x)+abs(a.y-b.y);
}
int dis[15010];
int main(){
	int n,k,minn,idx;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&coor[i].x,&coor[i].y);
		dis[i] = 1e9;
	}
	dis[1] = 0;
	for(int i=1;i<n;i++){
		minn = 1e9;
		for(int j=i+1;j<=n;j++){
			dis[j] = min(dis[j],find_dis(coor[i],coor[j]));
			if(dis[j]<minn){
				minn = dis[j];
				idx = j;
			}
		}
		swap(dis[i+1],dis[idx]);
		swap(coor[i+1],coor[idx]);
	}
	sort(dis+1,dis+n+1);
	int sum = 0;
	for(int i=1;i<=n-k+1;i++)
		sum+=dis[i];
	printf("%d\n",sum);
	return 0;
}
