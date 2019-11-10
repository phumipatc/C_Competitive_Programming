/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int f[1000010],sieve[1000010];
vector<int > prime;
int main(){
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(int i=3;i<=1000000;i+=2)
		sieve[i] = 1;
	prime.push_back(2);
	// f[2] = 1;
	for(int i=3;i<=sqrt(1000000);i++){
		if(!sieve[i])	continue;
		prime.push_back(i);
		// f[i] = 1;
		for(int j=i*i;j<=1000000;j+=i)
			sieve[j] = 0;
	}
	for(int i=sqrt(1000000)+1;i<=1000000;i++){
		if(!sieve[i])	continue;
		prime.push_back(i);
	}
	memset(f,-1,sizeof f);
	f[1] = 0;
	for(auto x:prime){
		for(int i=x;i<=1000000;i+=x){
			if(f[i/x] == -1)	continue;
			f[i] = f[i/x]+1;
		}
	}
	int l,r,maxx = 0,ansl = 0,ansr = 0;
	for(int i=2;i<=b;i++){
		r = b/i,l = (a-1)/i;
		if(l == r)	continue;
		r = d/i,l = (c-1)/i;
		if(l == r)	continue;
		if(maxx<f[i]){
			maxx = f[i];
			ansl = (b/i)*i;
			ansr = (d/i)*i;
		}else if(maxx == f[i]){
			int tl = (b/i)*i,tr = (d/i)*i;
			if(ansl+ansr>tl+tr)	continue;
			if(ansl+ansr<tl+tr){
				ansl = tl,ansr = tr;
				continue;
			}
			if(ansl>tl)	continue;
			ansl = tl,ansr = tr;
		}
	}
	printf("%d %d\n",ansl,ansr);
	return 0;
}