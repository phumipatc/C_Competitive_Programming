/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,val;
    bool operator < (const A&o) const{
        return val>o.val;
    }
};
priority_queue< A> heap;
int a[500001];
int main(){
    int n,k,ans=0,num;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    heap.push({1,a[1]});
    for(int i=2;i<=n;i++){
        while(!heap.empty()){
            if(heap.top().idx<i-k){
                heap.pop();
                continue;
            }
            a[i]+=heap.top().val;
            heap.push({i,a[i]});
            break;
        }
    }
    printf("%d\n",a[n]);
    return 0;
}
