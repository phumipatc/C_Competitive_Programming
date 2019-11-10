/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
priority_queue<long long > heap;
int main(){
    long long d,k,n,b,ans = 0,num;
    scanf("%lld %lld",&d,&k);
    for(long long i=0;i<d;i++){
        scanf("%lld %lld",&n,&b);
        for(long long j=1;j<=n;j++){
            scanf("%lld",&num);
            heap.push(num-(i*k));
        }
        while(b--){
            ans+=heap.top()+(i*k);
            heap.pop();
        }
    }
    printf("%lld\n",ans);
	return 0;
}
