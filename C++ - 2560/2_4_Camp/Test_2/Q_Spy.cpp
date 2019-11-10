/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[1100];
struct A{
    long long a,b,weight;
    bool operator < (const A&o) const{
        return weight < o.weight;
    }
};
long long findroot(int i){
    if(p[i]==i)
        return i;
    return p[i]=findroot(p[i]);
}
A a[2000000];
int main(){
    long long n,i,j,idx=0,ans=0,ra,rb;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)   p[i]=i;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            idx++;
            scanf("%lld",&a[idx].weight);
            a[idx].a=i;
            a[idx].b=j;
        }
    }
    for(i=1;i<=n;i++){
        idx++;
        scanf("%lld",&a[idx].weight);
        a[idx].a=i;
        a[idx].b=n+1;
    }
    sort(a+1,a+idx+1);
    for(i=1;i<=idx;i++){
        ra=findroot(a[i].a);
        rb=findroot(a[i].b);
        if(ra!=rb){
            p[rb]=ra;
            ans+=a[i].weight;
        }
    }
    printf("%lld\n",ans);
	return 0;
}
