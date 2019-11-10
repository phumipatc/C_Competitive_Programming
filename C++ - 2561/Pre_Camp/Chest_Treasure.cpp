/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long pos,f[8];
	bool operator < (const A&o) const{
		if(pos!=o.pos)	return pos<o.pos;
		else			return (f[2]+f[3]+f[5]+f[7])<(o.f[2]+o.f[3]+o.f[5]+o.f[7]);
	}
};
A a[400010];
long long m,f[10];
void check(long long v,long long pos){
	while(v%2 == 0)	a[pos].f[2]++,a[pos+m].f[2]++,v/=2;
	while(v%3 == 0)	a[pos].f[3]++,a[pos+m].f[3]++,v/=3;
	while(v%5 == 0)	a[pos].f[5]++,a[pos+m].f[5]++,v/=5;
	while(v%7 == 0)	a[pos].f[7]++,a[pos+m].f[7]++,v/=7;
}
int main(){
	long long n,v,st,en,num,maxx = 0,ans;
	scanf("%lld %lld",&m,&n);
	for(long long i=1;i<=m;i++){
		scanf("%lld %lld %lld",&v,&st,&en);
		check(v,i);
		a[i].pos = st;
		a[i+m].pos = en+1;
		for(long long j=2;j<=7;j++)
			a[i+m].f[j]*=-1;
	}
	sort(a+1,a+(2*m)+1);
	for(long long i=1;i<2*m;i++){
		for(long long j=2;j<=7;j++)
			f[j]+=a[i].f[j];
		num = (f[2]+1)*(f[3]+1)*(f[5]+1)*(f[7]+1);
		// printf("%lld %lld %lld %lld %lld %lld\n",a[i].pos,f[2],f[3],f[5],f[7],num);
		if(num>maxx){
			maxx = num;
			ans = a[i+1].pos-a[i].pos;
		}else if(num == maxx){
			ans+=a[i+1].pos-a[i].pos;
		}
	}
	printf("%lld %lld\n",maxx,ans);
	return 0;
}
