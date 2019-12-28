/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double a[10010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k;
	double sum = 0;
	cin >> n >> k;
	printf("%d\n",n-k+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
		if(i<k) continue;
		sum-=a[i-k];
		printf("%lf ",sum/k);
		// cout << (double)sum/k << ' ';
	}
	return 0;
}