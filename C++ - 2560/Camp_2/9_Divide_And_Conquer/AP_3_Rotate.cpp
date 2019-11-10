/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],n,b[100100],ans=0;
void mergesort(int l, int r){
    if(l==r)    return;
    int mid = (l+r)/2;
    //divide
    mergesort(l,mid);
    mergesort(mid+1,r);
    //conquer
    int i=l, j=mid+1, k=l;
    while(i<=mid && j<=r){
        if(a[i] <= a[j])
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
    return;
}

int main()
{
    int i,q;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        ans=0;
        mergesort(0,n-1);
        if(ans%2==0)    printf("yes\n");
        else            printf("no\n");
    }
    return 0;
}
/*
3
5
3 1 2 4 5
4
2 4 3 1
5
1 2 5 4 3
*/
