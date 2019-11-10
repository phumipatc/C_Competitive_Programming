/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,idx,ans = 1e9;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int last = 0;
    for(int i=0;i<n;i++){
        if(a[i] == a[i+1])  continue;
        idx = upper_bound(a,a+n,2*a[i])-a;
        // printf("%d : %d %d\n",i,idx,last+n-idx);
        ans = min(ans,last+n-idx);
        last = i+1;
    }
    printf("%d\n",ans);
	return 0;
}
