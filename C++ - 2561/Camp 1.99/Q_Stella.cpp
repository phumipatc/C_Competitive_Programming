/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long mana,hl,last,ty,st;
    bool operator < (const A&o) const{
        if(mana!=o.mana)    return mana<o.mana;
        else                return st>o.st;
    }
};
A now;
priority_queue< A> heap;
int main(){
    long long n,m,hl,ans = 0;
    char opr,ty;
    scanf("%lld",&n);
    for(long long d=1;d<=n;d++){
        scanf(" %c",&opr);
        if(opr == 'c'){
            scanf(" %c %lld",&ty,&m);
            if(ty == 'n'){
                heap.push({m,0,0,1,d});
            }else if(ty == 'r'){
                scanf("%lld",&hl);
                heap.push({m,hl,d,2,d});
            }
        }else{
            while(!heap.empty()){
                now = heap.top();
                heap.pop();
                if(now.ty == 2 && (d-now.last)>=now.hl){
                    long long c = (d-now.last)/now.hl;
                    for(long long i=1;i<=c;i++)   now.mana/=2;
                    now.last+=c*now.hl;
                    if(now.mana != 0)
                        heap.push(now);
                    continue;
                }
                ans+=now.mana;
                break;
            }
        }
    }
    long long ans2 = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(now.ty == 2){
            long long c = (n-now.last)/now.hl;
            for(long long i=1;i<=c;i++)   now.mana/=2;
            if(now.mana == 0)   continue;
        }
        ans2++;
    }
    printf("%lld\n%lld\n",ans,ans2);
	return 0;
}
