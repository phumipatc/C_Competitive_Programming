/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[300010];
int main(){
    int n,k,idx,maxx = 0,l,r;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=1;
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        idx = lower_bound(a,a+i,a[i]-k)-a+1;
        // printf("%d %d\n",i,idx);
        if(i-idx+1>maxx){
            maxx = i-idx+1;
            l = idx,r = i;
        }
    }
    printf("%d\n",maxx);
    for(int i=1;i<=n;i++){
        if(i>=l && i<=r)    printf("1 ");
        else                printf("%d ",(a[i]-a[i-1])^1);
    }
	return 0;
}