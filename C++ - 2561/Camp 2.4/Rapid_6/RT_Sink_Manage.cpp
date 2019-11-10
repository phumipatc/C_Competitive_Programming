/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,w;
    bool operator < (const A&o) const{
        if(w!=o.w)   return w<o.w;
        else        return l>o.l;
    }
};
priority_queue<A > heap;
int a[100010],Q[100010];
int main(){
    int m,n,q,maxx;
    scanf("%d %d %d",&m,&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    a[0] = 0;
    a[n+1] = m+1;
    for(int i=1;i<=n+1;i++){
        if(a[i]-a[i-1]-1<=0)    continue;
        // printf("%d %d %d\n",a[i-1]+1,a[i]-1,a[i]-a[i-1]-1);
        heap.push({a[i-1]+1,a[i]-1,a[i]-a[i-1]-1});
    }
    maxx = n;
    for(int i=1;i<=q;i++){
        scanf("%d",&Q[i]);
        maxx = max(maxx,Q[i]);
    }
    int now = n+1;
    while(now<=maxx){
                
    }
    return 0;
}
