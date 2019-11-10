/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(st!=o.st)    return st<o.st;
        else            return en<o.en;
    }
};
A a[100100];
priority_queue< int> heap;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en);
    sort(a+1,a+n+1);
    heap.push(-a[1].en);
    for(int i=2;i<=n;i++){
        if(-a[i].st<heap.top())
            heap.pop();
        heap.push(-a[i].en);
    }
    printf("%d\n",heap.size());
    return 0;
}
