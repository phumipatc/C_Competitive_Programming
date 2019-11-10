/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],qs[100100],ans;
void merge_sort(long long l,long long r){
    if(l==r)    return ;
    long long mid=(l+r)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    long long i=l,j=mid+1,idx=l;
    while(i<=mid && j<=r){
        if(a[i]>a[j])
            b[idx++]=a[j++],ans+=(a[j-1]*(mid-i+1))+(qs[mid]-qs[i-1]);
        else
            b[idx++]=a[i++];
    }
    while(i<=mid)   b[idx++]=a[i++];
    while(j<=r)     b[idx++]=a[j++];
    for(i=l;i<=r;i++){
        a[i]=b[i];
        qs[i]=a[i]+qs[i-1];
    }
}
int main(){
    long long q,n;
    scanf("%lld",&q);
    while(q--){
        ans=0;
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            qs[i]=a[i]+qs[i-1];
        }
        merge_sort(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
