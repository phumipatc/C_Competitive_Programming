/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
PII p[100100];
long long a[100100],b[100100],quicksum[100100],ans;
void mergesort(long long l,long long r){
    if(l==r)    return ;
    long long mid=(l+r)/2,i,j,k;
    mergesort(l,mid);
    mergesort(mid+1,r);
    quicksum[l-1]=0;
    for(i=l;i<=r;i++)
        quicksum[i]=quicksum[i-1]+a[i];
    i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<a[j])
            b[k++]=a[i++];
        else{
            ans+=((mid-i+1)*a[j])+quicksum[mid]-quicksum[i-1];
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
    printf("%lld\n",ans);
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

4
1 4
3 2
2 3
7 1
*/
