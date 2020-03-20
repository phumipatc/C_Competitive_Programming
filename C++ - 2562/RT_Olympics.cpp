/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[30],qs[30];
int ans,m,p;
void recurse(int n,int state){
	// printf("%d %d:",n,state);
	// for(int i=1;i<=state;i++)
	// 	printf("%d ",a[i]);
	// printf("\n");
	if(n == 0 && state == m+1){
		ans = 0;
		return ;
	}
	if(state == m){
		a[state]+=n;
		qs[state] = qs[state-1]+a[state];
		if(qs[state]>=p){
			int idx = lower_bound(qs,qs+state,qs[state]-p)-qs;
			if(qs[idx] == qs[state]-p){
				a[state]-=n;
				return ;
			}
		}
		recurse(0,state+1);
		if(!ans)	return ;
		a[state]-=n;
		return ;
	}
	for(int i=0;i<=n;i++){
		a[state]+=i;
		qs[state] = qs[state-1]+a[state];
		if(qs[state]>=p){
			int idx = lower_bound(qs,qs+state,qs[state]-p)-qs;
			if(qs[idx] == qs[state]-p){
				a[state]-=i;
				continue;
			}
		}
		recurse(n-i,state+1);
		if(!ans)	return ;
		a[state]-=i;
	}
}
int main(){
	int q,n;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&n,&m,&p);
		for(int i=1;i<=m;i++)
			a[i] = 1;
		ans = 1;
		n-=m;
		recurse(n,1);
		printf((ans)?"yes\n":"no\n");
	}
	return 0;
}