/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int q,n,k,sum,idx1,idx2;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&k);
		sum = 0;
		for(int i=n-1;i>=1;i--){
			sum+=n-i;
			if(sum>=k){
				idx1 = i;
				sum-=n-i,k-=sum;
				idx2 = n-k+1;
				break;
			}
		}
		for(int i=1;i<=n;i++)
			printf((i == idx1 || i == idx2)?"b":"a");
		printf("\n");
	}
	return 0;
}