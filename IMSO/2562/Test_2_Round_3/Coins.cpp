/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[1000010],b[1000010],temp[1000010];
int dp[1000010][2],mi[1000010],ma[1000010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,maxx = 0,pos;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> b[i];
		if(maxx<b[i]){
			maxx = b[i];
			pos = i;
		}
		temp[i] = b[i]+temp[i-1];
		ma[b[i]] = max(ma[b[i]],i);
		if(!mi[b[i]])	mi[b[i]] = i;
	}
	if(maxx>=temp[pos-1]+temp[n]-temp[pos]){
		//Case 1: can be linear
		//Rearrange array
		for(int i=1;i<=n;i++)
			temp[i] = a[i];
		for(int i=pos+1;i<=n;i++)
			a[i-pos] = temp[i];
		for(int i=1;i<=pos;i++)
			a[i+n-pos] = temp[i];
		for(int i=1;i<=n;i++)
			temp[i] = b[i];
		for(int i=pos+1;i<=n;i++)
			b[i-pos] = temp[i];
		for(int i=1;i<=pos;i++)
			b[i+n-pos] = temp[i];
		for(int i=1;i<=n;i++)
			b[i]+=b[i-1];
	}else{
		//Case 2: still have cycle
	}
	return 0;
}
//2 cases
//1 can be linear
//still have cycle