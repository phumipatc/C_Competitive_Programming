/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10],dp[1000200];
int main(){
	int q,n,m,countt;
	scanf("%d",&q);
	for(int x = 1;x<=q;x++){
        countt = 0;
        scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
            dp[a[i]] = x;
		}
		sort(a+1,a+n+1);
		dp[0] = x;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
                if(i<a[j] || dp[i-a[j]] != x)   continue;
                countt++;
                dp[i] = x;
                break;
			}
		}
        printf("%d\n",countt);
	}
	return 0;
}
