/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long ,long long > PII;
PII p[100100];
long long a[100100],b[100100],qs[100100],ans;
void merge_sort(long long l,long long r){
    if(l == r)  return ;
    long long mid=(l+r)/2,i,j,k;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    qs[l-1] = 0;
    for(i=l;i<=r;i++)
        qs[i] = qs[i-1]+a[i];
    i = k = l,j = mid+1;
    while(i<=mid && j<=r){
        if(a[i]<a[j])
            b[k++] = a[i++];
        else{
            ans+=((mid-i+1)*a[j])+(qs[mid]-qs[i-1]);
            b[k++] = a[j++];
        }
    }
    while(i<=mid)   b[k++] = a[i++];
    while(j<=r)     b[k++] = a[j++];
    for(i=l;i<=r;i++)
        a[i] = b[i];
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&p[i].first,&p[i].second);
    sort(p+1,p+n+1);
    for(long long i=1;i<=n;i++)
        a[i]=p[i].second;
    merge_sort(1,n);
    printf("%lld\n",ans);
    return 0;
}
