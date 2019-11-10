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
priority_queue< A> heap;
int main(){
    int n,k,num;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        while(!heap.empty() && i-heap.top().v>k)    heap.pop();
        if(i == 1)  heap.push({i,num});
        else        heap.push({i,heap.top().w+num});
    }
    while(!heap.empty() && heap.top().v!=n) heap.pop();
    printf("%d\n",heap.top().w);
    return 0;
}
