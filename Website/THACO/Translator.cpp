/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	language: C++
	Algo	: Binary Search
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
int a[100010];
int mark[100010],num[100010];
int ans[100010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,q,countt,now,k = 0;
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		if(mark[i])	continue;
		now = a[i];
		mark[i] = 1;
		countt = 1;
		while(now!=i){
			mark[now] = 1;
			now = a[now];
			countt++;
		}
		// printf("%d %d\n",k,countt);
		num[++k] = countt-1;
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=num[i];j++)
			ans[j]+=num[i]/j;
	// for(int i=1;i<=n;i++)
	// 	printf("%d ",ans[i]);
	int x,l,r,mid;
	while(q--){
		cin >> x;
		l = 1,r = n;
		while(l<r){
			mid = (l+r)/2;
			if(ans[mid]<=x)	r = mid;
			else			l = mid+1;
		}
		cout << r << '\n';
	}
	return 0;
}