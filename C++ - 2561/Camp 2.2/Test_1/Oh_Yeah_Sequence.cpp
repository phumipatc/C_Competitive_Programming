/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long v,w;
    bool operator < (const A&o) const{
        return v<o.v;
    }
};
A temp;
priority_queue<A > heap;
long long a[200010];
int main(){
    long long n,opr,now = 1,u,v,sum = 0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&opr);
        if(opr == 1){
            scanf("%lld %lld",&u,&v);
            heap.push({u,v});
            sum+=u*v;
        }else if(opr == 2){
            scanf("%lld",&v);
            now++;
            a[now] = v;
            sum+=v;
        }else if(opr == 3){
            sum-=a[now];
            now--;
            while(!heap.empty()){
                temp = heap.top();
                if(temp.v<=now) break;
                heap.pop();
                sum-=temp.w;
                if(temp.v == 1) continue;
                heap.push({temp.v-1,temp.w});
            }
        }
        printf("%lld %lld\n",sum,now);
    }
	return 0;
}
