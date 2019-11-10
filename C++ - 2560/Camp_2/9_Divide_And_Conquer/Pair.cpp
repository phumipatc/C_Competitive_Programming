/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> p[100100];
long long ans,qs[100100],a[100100],b[100100];
void mergesort(long long l,long long r){
    if(l==r)    return ;
    long long mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    qs[l-1]=0;
    for(long long i=l;i<=r;i++)
        qs[i]=qs[i-1]+a[i];
    long long i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k++]=a[i++];
        }else if(a[i]>a[j]){
            ans+=((mid-i+1)*a[j])+qs[mid]-qs[i-1];
            b[k++]=a[j++];
        }
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=r)
        b[k++]=a[j++];
    for(i=l;i<=r;i++)
        a[i]=b[i];
}
int main()
{
    long long n,i;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&p[i].second,&p[i].first);
    sort(p,p+n);
    for(i=0;i<n;i++)
        a[i+1]=p[i].second;
    mergesort(1,n);
    printf("%lld",ans);
    return 0;
}
/*
6
2 1
7 6
9 3
18 4
3 2
5 5
*/
