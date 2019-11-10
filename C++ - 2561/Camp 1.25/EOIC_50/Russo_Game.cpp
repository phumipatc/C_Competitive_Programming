/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    int n,ans = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n-1;i>=1;i--){
        if(a[i]>a[i+1]){
            ans+=a[i]-a[i+1]+1;
            a[i] = a[i+1]-1;
        }
    }
    printf("%d\n",ans);
	return 0;
}
