/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a,b;
    bool operator < (const A&o) const{
        return b<o.b;
    }
};
A p[100010];
long long a[100010],b[100010],qs[100010],ans = 0;
void merge_sort(long long l,long long r){
    if(l == r)  return ;
    long long mid = (l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    qs[l-1] = 0;
    for(long long i=l;i<=r;i++)
        qs[i] = qs[i-1]+a[i];
    long long i = l,j = mid+1,k = l;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        }else{
            ans+=(qs[mid]-qs[i-1])+((mid-i+1)*a[j]);
            b[k++] = a[j++];
        }
    }
    while(i<=mid)   b[k++] = a[i++];
    while(j<=r)     b[k++] = a[j++];
    for(long long k=l;k<=r;k++)
        a[k] = b[k];
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&p[i].a,&p[i].b);
    sort(p+1,p+n+1);
    for(long long i=1;i<=n;i++)
        a[i] = p[i].a;
    merge_sort(1,n);
    printf("%lld\n",ans);
	return 0;
}
