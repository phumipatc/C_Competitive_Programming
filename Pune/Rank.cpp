#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,m,num,idx;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	while(m--){
		scanf("%d",&num);
		idx = lower_bound(a+1,a+n+1,num)-(a+1);
		printf("%d\n",n-idx+1);
	}
	return 0;
}