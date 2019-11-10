/*
    Author  : Bentor
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	// int n = 10000;
	// for(int i=1;i<=n;i++){
	// 	if(n%i)		continue;
	// 	if(i*4<300)	continue;
	// 	if(i*4>500)	break;
	// 	printf("%d\n",i);
	// }
	int m,asum,anum,i,j,k,l;
	double minn = 100,aget;
	i = j = k = l = 10;
	cin >> m;
	int exp = 10*i + 10*j + 20*k + 20*l;
	for(int x=1;x<=m;x++){
		int ni = 1000*i;
		int nj = 1000*j;
		int nk = 1000*k;
		int nl = 1000*l;
		if(ni%x)	continue;
		if(nj%x)	continue;
		if(nk%x)	continue;
		if(nl%x)	continue;
		int sum = ni/x + nj/x + nk/x + nl/x;
		if(sum<300 || sum>500)	continue;
		if(exp>20*x)	continue;
		if(minn>exp/x){
			minn = exp/x;
			asum = sum,aget = (double )exp/x,anum = x;
		}
		// printf("%d %f %d\n",sum,(float )exp/x,x);
	}
	printf("%d %f %d\n",asum,(float )aget,anum);
    return 0;
}