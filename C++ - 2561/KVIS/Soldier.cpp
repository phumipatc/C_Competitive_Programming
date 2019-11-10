/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int id,t,r;
    bool operator < (const A&o) const{
        if(r!=o.r)  return r<o.r;
        else        return t>o.t;
    }
};
A now;
priority_queue< A> heap;
int main(){
    int n,m,opr;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d",&now.id,&now.r);
            now.t = i;
            heap.push(now);
        }else{
            if(heap.empty()){
                printf("-1\n");
                continue;
            }
            printf("%d\n",heap.top().id);
            heap.pop();
        }
    }
	return 0;
}
