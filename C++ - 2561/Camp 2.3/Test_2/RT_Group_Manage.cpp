/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[3010];
int main(){
    int n,minn,maxx,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        minn = 1e9,maxx = 0;
        for(int j=i;j<=n;j++){
            maxx = max(maxx,a[j]);
            minn = min(minn,a[j]);
            if(maxx-minn+1 == j-i+1)    ans++;
        }
    }
    printf("%d\n",ans);
	return 0;
}
