/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[100010];
int k,A,B;
int divide(int l,int r){
	if(l == r){
		int ll = lower_bound(a+1,a+k+1,l)-a;
		int rr = upper_bound(a+1,a+k+1,r)-a-1;
		int cost = 0;
		//Have watch
		if(rr-ll+1>0){
			cost = B * (rr-ll+1) * (r-l+1);
		}else{
			cost = A;
		}
		//Dont have watch
		return cost;
	}
	int ll = lower_bound(a+1,a+k+1,l)-a;
	int rr = upper_bound(a+1,a+k+1,r)-a-1;
	if(rr-ll+1<=0)	return A;
	int mid = (l+r)/2;
	return min(divide(l,mid)+divide(mid+1,r),B * (rr-ll+1) * (r-l+1));
}
int main(){
	int n;
	scanf("%d %d %d %d",&n,&k,&A,&B);
	n = 1<<n;
	for(int i=1;i<=k;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+k+1);
	printf("%d\n",divide(1,n));
	return 0;
}