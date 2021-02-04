/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[1]++,b[a[i]+1]--;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=a[n];i++)
        b[i]+=b[i-1];
    int ans = 0,countt = 0;
    for(int i=a[n];i>a[1];i--){
        if(countt+b[i]>k)   countt = 0,ans++;
        countt+=b[i];
    }
    if(countt)  ans++;
    printf("%d\n",ans);
	return 0;
}