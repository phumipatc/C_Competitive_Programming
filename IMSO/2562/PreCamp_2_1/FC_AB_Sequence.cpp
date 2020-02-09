/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	int sum = 0;
	for(int i=1;i<=n;i++){
		a[i]*=i;
		a[i]-=sum;
		sum+=a[i];
		printf("%d ",a[i]);
	}
	return 0;
}