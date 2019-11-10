/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long > heap;
int main(){
    long long l,k,sum = 0,x,y;
    scanf("%lld %lld",&l,&k);
    for(long long i=1;i<=k;i++){
        scanf("%lld %lld",&x,&y);
        sum+=y;
        heap.push(-(x-y));
    }
    while(!heap.empty() && l-- && -heap.top()<0){
        sum-=heap.top();
        heap.pop();
    }
    printf("%lld\n",sum);
	return 0;
}
