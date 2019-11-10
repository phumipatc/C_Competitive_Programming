/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,idx;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    if(a[n]%2 == 0){
        idx = lower_bound(a+1,a+n+1,a[n]/2)-a;
        if(a[idx] == a[n]/2){
            printf("%d\n",idx);
            return 0;
        }
    }
    for(int i=1;i<=n-2;i++){
        int l = i+1,r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(a[mid]-a[i]>=a[i]+a[n]-a[mid])   r = mid;
            else                                l = mid+1;
        }
        if(l == n-1 || a[l]-a[i]!=a[i]+a[n]-a[l])   continue;
        printf("%d %d\n",i,l);
        return 0;
    }
    printf("NO\n");
	return 0;
}