/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v;
    bool operator < (const A&o) const{
        return v>o.v;
    }
};
priority_queue< A> heap;
int main(){
    long long q,countt,n,m,k,num,opr;
    scanf("%lld",&q);
    while(q--){
        countt = 0;
        scanf("%lld %lld %lld",&n,&m,&k);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&num);
            heap.push({num});
        }
        while(m--){
            scanf("%lld",&opr);
            if(opr == 1){
                scanf("%lld",&num);
                heap.push({num-(countt*k)});
            }else if(opr == 2)
                countt++;
            else if(opr == 3){
                if(!heap.empty()){
                    heap.pop();
                }
            }
        }
        printf("%lld ",heap.size());
        long long ans = 0;
        while(!heap.empty()){
            ans+=heap.top().v+(countt*k);
            heap.pop();
        }
        printf("%lld\n",ans);
    }
	return 0;
}
