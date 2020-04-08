/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[55][55];
int main(){
	int q,n,k;
	scanf("%d",&q);
	for(int x=1;x<=q;x++){
		scanf("%d %d",&n,&k);
		memset(a,0,sizeof a);
		if(k%n == 0){
			for(int i=0;i<n;i++){
				a[i][i] = k/n;
				int now = 1;
				for(int j=1;j<n;j++){
					if(now == k/n)	now++;
					a[i][(i+j)%n] = now++;
				}
			}
		}else if((1+n)*n/2 == k){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					
				}
			}
		}
		printf("Case #%d: ",x);
		if(a[0][0] == 0){
			printf("IMPOSSIBLE\n");
			continue;
		}
		printf("POSSIBLE\n");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}