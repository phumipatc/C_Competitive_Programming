/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int len,l,r;
    bool operator < (const A&o) const{
        if(len!=o.len)  return len<o.len;
        else            return l>o.l;
    }
};
priority_queue< A> heap;
int a[100005];
int main(){
    int m,n,q,maxx = -1,idx = 1;
    scanf("%d %d %d",&m,&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[0] = 0;
    a[n+1] = m+1;
    for(int i=0;i<=n;i++)
        heap.push({a[i+1]-a[i]-1,a[i],a[i+1]});
    return 0;
}
