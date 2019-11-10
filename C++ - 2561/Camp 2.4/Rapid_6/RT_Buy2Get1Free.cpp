/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int now = n,ans = 0;
	while(now>0){
		if(now>=3){
			ans+=a[now]+a[now-1];
			now-=3;
		}else{
			ans+=a[now];
			now--;
		}
	}
	printf("%d\n",ans);
	return 0;
}
