/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long value,k;
};
deque< A> deq;
long long a[300100],rmax[300100],lmax[300100],lmin[300100],rmin[300100];
int main(){
    long long n,i,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=n;i>0;i--){
        while(!deq.empty()){
            if(a[i]<deq.back().value)   break;
            rmax[i]+=deq.back().k+1;
            deq.pop_back();
        }
        deq.push_back({a[i],rmax[i]});
    }
    while(!deq.empty())   deq.pop_back();
    for(i=1;i<=n;i++){
        while(!deq.empty()){
            if(a[i]<=deq.back().value)   break;
            lmax[i]+=deq.back().k+1;
            deq.pop_back();
        }
        deq.push_back({a[i],lmax[i]});
    }
    while(!deq.empty())   deq.pop_back();
    for(i=n;i>0;i--){
        while(!deq.empty()){
            if(a[i]>deq.back().value)   break;
            rmin[i]+=deq.back().k+1;
            deq.pop_back();
        }
        deq.push_back({a[i],rmin[i]});
    }
    while(!deq.empty())   deq.pop_back();
    for(i=1;i<=n;i++){
        while(!deq.empty()){
            if(a[i]>=deq.back().value)   break;
            lmin[i]+=deq.back().k+1;
            deq.pop_back();
        }
        deq.push_back({a[i],lmin[i]});
    }
    for(i=1;i<=n;i++)
        ans+=a[i]*((((rmax[i]+1)*(lmax[i]+1))-1)-(((rmin[i]+1)*(lmin[i]+1))-1));
    printf("%lld\n",ans);
    return 0;
}
