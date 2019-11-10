/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],mark[5010];
int main(){
    int n,ans = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        a[i]--;
    }
    for(int i=1;i<n;i++){
        if(mark[i]) continue;
        ans++;
        for(int j=i+1;j<n;j++)
            if(a[j]%a[i] == 0)
                mark[j] = 1;
    }
    printf("%d\n",ans);
	return 0;
}
