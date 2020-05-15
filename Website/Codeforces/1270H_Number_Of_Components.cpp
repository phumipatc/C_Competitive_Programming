/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,ans = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
        ans+=a[i]*(n-a[i]+1);
    }
	for(int i=2;i<=n;i++){
		if(a[i]>=a[i-1])    ans-=a[i-1]*(n-a[i]+1);
		else                ans-=a[i]*(n-a[i-1]+1);
	}
	printf("%d\n",ans);
}