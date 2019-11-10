/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
int main(){
    long long n,l = 0,r = 0,now,mid,ch;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]*=1e6;
        r = max(r,a[i]);
    }
    while(l<r){
        mid = (l+r)/2,now = ch = 0;
        for(int i=1;i<=n;i++){
            if(now<=a[i])           now = max(now,a[i]-mid);
            else if(now-a[i]>mid){
                ch = 1;
                break;
            }
        }
        if(ch)  l = mid+1;
        else    r = mid;
    }
    printf("%lld.%06lld\n",l/(long long )(1e6),l%(long long )(1e6));
	return 0;
}