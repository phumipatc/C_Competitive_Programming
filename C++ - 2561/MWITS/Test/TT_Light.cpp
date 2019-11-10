/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,l,r,mid;
    scanf("%lld",&n);
    l = 1,r = 1e9;
    while(l<r){
        mid = (l+r+1)/2;
        if(mid*mid>n)   r = mid-1;
        else            l = mid;
    }
    printf("%lld\n",l);
	return 0;
}
