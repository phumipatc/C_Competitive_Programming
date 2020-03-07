/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[300010],b[100010];
vector<long long > v[30];
long long tree[300010];
void upd(long long idx,long long v){
	while(idx<=300003){
		tree[idx]+=v;
		idx+= idx & -idx;
	}
}
long long query(long long idx){
	long long sum = 0;
	while(idx>0){
		sum+=tree[idx];
		idx-= idx & -idx;
	}
	return sum;
}
int main(){
	long long opr,n,m;
	scanf("%lld %s %s",&opr,a+1,b+1);
	n = strlen(a+1),m = strlen(b+1);
	for(long long i=n;i>=1;i--)
		v[a[i]-'a'].push_back(i);
	long long ans = 0;
	for(long long i=1;i<=m;i++){
		if(v[b[i]-'a'].empty()){
			printf("-1\n");
			return 0;
		}
		ans+=v[b[i]-'a'].back();
		if(opr == 1)	ans-=query(v[b[i]-'a'].back());
		upd(v[b[i]-'a'].back(),1);
		v[b[i]-'a'].pop_back();
	}
	printf("%lld\n",ans);
	return 0;
}