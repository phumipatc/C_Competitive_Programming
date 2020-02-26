/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int main(){
	freopen("10.in","r",stdin);
	freopen("10.sol","w",stdout);
    int n,maxx = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
        maxx = max(maxx,min(a[i],b[n-i+1]));
    printf("%d\n",maxx);
	return 0;
}