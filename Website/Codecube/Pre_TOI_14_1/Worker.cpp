/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w>o.w;
        else        return u<o.u;
    }
};
priority_queue< A> heap;
long long value[1100][1100],a[1100],b[1100],p[1100];
long long findroot(long long i){
    if(p[i]==i) return i;
    else        return p[i]=findroot(p[i]);
}
int main(){
    long long n,i,j;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)   scanf("%lld",&value[0][i]),p[i]=i;
    for(i=1;i<=n;i++)   scanf("%lld",&b[i]);
    for(i=1;i<=n;i++)   heap.push({0,i,value[0][i]});
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            value[i][j]=b[i]+b[j];
            heap.push({i,j,value[i][j]});
        }
    }
    long long ans=0;
    while(!heap.empty()){
        A temp=heap.top();
        heap.pop();
        long long ru=findroot(temp.u),rv=findroot(temp.v);
        if(ru!=rv){
            p[ru]=p[rv];
            ans+=temp.w;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
