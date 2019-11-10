/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x<o.x;
        else        return y<o.y;
    }
};
A a[500010];
long long tree[1000010],l[500010],r[500010];
void update(long long idx,long long v){
    while(idx<=1000003){
        tree[idx]+=v;
        idx+=idx & -idx;
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx & -idx;
    }
    return sum;
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        l[i] = query(a[i].y);
        update(a[i].y,1);
    }
    memset(tree,0,sizeof tree);
    for(long long i=n;i>=1;i--){
        r[i] = query(1000000)-query(a[i].y-1);
        update(a[i].y,1);
    }
    long long ans = 0;
    for(long long i=1;i<=n;i++){
        ans+=l[i]*r[i];
    }
    printf("%lld\n",ans);
	return 0;
}
