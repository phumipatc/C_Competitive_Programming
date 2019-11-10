/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long s,m;
    scanf("%lld %lld",&s,&m);
    long long l=1,r = s/2,mid;
    while(l<=r){
        mid = (l+r)/2;
        if((s-mid)*mid > m || (mid*(s-mid))/(s-mid)!=mid)   r = mid-1;
        else if((s-mid)*mid < m)                            l = mid+1;
        else{
            printf("%lld %lld\n",mid,s-mid);
            return 0;
        }
    }
    printf("Goodbye T-T\n");
	return 0;
}
