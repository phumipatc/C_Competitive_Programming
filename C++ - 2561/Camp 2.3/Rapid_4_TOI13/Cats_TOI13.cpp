/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000010],b[2000010];
int main(){
    long long n,maxx = 0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxx = max(maxx,a[i]);
    }
    long long l = 0,r = maxx,mid,idx,ch;
    while(l<r){
        mid = (l+r)/2,idx = 1,ch = 1;
        for(int i=1;i<=n;i++){
            if(a[i]<=mid)   continue;
            b[idx++] = a[i];
        }
        for(int i=1;i<idx;i+=2){
            if(b[i]!=b[i+1]){
                ch = 0;
                break;
            }
        }
        if(ch)  r = mid;
        else    l = mid+1;
    }
    printf("%lld\n",l);
	return 0;
}
