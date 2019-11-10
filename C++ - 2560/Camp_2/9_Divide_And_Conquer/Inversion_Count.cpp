/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],n,b[100100];
long long ans;
void mergesort(int l,int r){
    if(l==r)    return ;
    int mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++],ans+=mid-i+1;
    }
        while(i<=mid)
            b[k++]=a[i++];
        while(j<=r)
            b[k++]=a[j++];
        for(i=l;i<=r;i++)
            a[i]=b[i];
        return ;

}
int main(){
    int n,i,now;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(0,n-1);
    printf("%lld",ans);
    return 0;
}
