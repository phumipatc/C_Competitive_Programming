 /*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100],ll[100100],rr[100100],idx[100100],ind[100100];
void mergesort(long long l,long long r){
    if(l==r)    return ;
    long long mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    long long i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            ind[k]=idx[i];
            rr[idx[i]]+=j-mid-1;
            b[k++]=a[i++];
        }else{
            ind[k]=idx[j];
            ll[idx[j]]+=mid-i+1;
            b[k++]=a[j++];
        }
    }
    while(i<=mid){
        ind[k]=idx[i];
        rr[idx[i]]+=r-mid;
        b[k++]=a[i++];
    }
    while(j<=r){
        ind[k]=idx[j];
        b[k++]=a[j++];
    }
    for(i=l;i<=r;i++){
        a[i]=b[i];
        idx[i]=ind[i];
    }
    return;
}
int main()
{
    long long q,ans,n,i,j;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            idx[i]=i;
        }
        mergesort(1,n);
        for(i=1,ans=0;i<=n;i++)
            ans+=(ll[i]*rr[i]);
        printf("%lld\n",ans);
        memset(b,0,sizeof b);
        memset(ll,0,sizeof ll);
        memset(rr,0,sizeof rr);
    }
    return 0;
}
