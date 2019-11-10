/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main(){
    int n,k,sum=0,maxx=-1;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxx=max(a[i],maxx);
        sum+=a[i];
    }
    int l=maxx,r=sum,countt;
    while(l<r){
        int mid=(l+r)/2;
        maxx=-1;
        countt=sum=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(sum>mid){
                maxx=max(maxx,sum-a[i]);
                countt++;
                sum=a[i];
            }
        }
        countt++;
        if(countt>k)    l=mid+1;
        else            r=mid;
    }
    maxx=-1,sum=0;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        if(sum>l){
            maxx=max(maxx,sum-a[i]);
            sum=a[i];
        }
    }
    maxx=max(maxx,sum);
    printf("%d\n",maxx);
    return 0;
}
