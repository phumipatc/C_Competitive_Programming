/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110][110],mark[110];
int main(){
	int q,n,r,c,sum;
	scanf("%d",&q);
	for(int x=1;x<=q;x++){
		scanf("%d",&n);
		sum = r = c = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&a[i][j]);
				if(i == j)	sum+=a[i][j];
				if(!mark[0] && mark[a[i][j]])	r++,mark[0] = 1;
				mark[a[i][j]] = 1;
			}
			memset(mark,0,sizeof mark);
		}
		for(int j=1;j<=n;j++){
			for(int i=1;i<=n;i++){
				if(!mark[0] && mark[a[i][j]])	c++,mark[0] = 1;
				mark[a[i][j]] = 1;
			}
			memset(mark,0,sizeof mark);
		}
		printf("Case #%d: %d %d %d\n",x,sum,r,c);
	}
	return 0;
}