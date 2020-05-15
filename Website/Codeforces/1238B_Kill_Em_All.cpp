/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int q,ans,n,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&r);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        ans = 0;
        for(int i=n;i>=1;i--){
            if(a[i] == a[i-1])  continue;
            if(a[i]-(ans*r)>0)  ans++;
        }
        printf("%d\n",ans);
    }
	return 0;
}