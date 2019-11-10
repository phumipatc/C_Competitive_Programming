/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue< A> heap;
int main(){
    int n,m;
    char opr;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n+m;i++){
        scanf(" %c",&opr);
        if(opr == 'T'){
            scanf("%d %d",&now.w,&now.v);
            heap.push(now);
        }else{
            if(heap.empty())    printf("0\n");
            else{
                printf("%d\n",heap.top().v);
                heap.pop();
            }
        }
    }
    return 0;
}
