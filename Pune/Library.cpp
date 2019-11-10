/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int q,i,n,k,l,r,mid,countt;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&k);
		l = 1,r = 0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			r = max(r,a[i]);
		}
		while(l<r){
			mid = (l+r+1)/2,countt = 0;
			for(i=1;i<=n;i++)
				if(mid<=a[i])
					countt++;
			if(countt<k)	r = mid-1;
			else			l = mid;
		}
		printf("%d\n",l);
	}
	return 0;
}
