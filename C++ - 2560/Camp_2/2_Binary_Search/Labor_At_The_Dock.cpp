/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main(){
    long long ans,p,q,mid,i,m,n,maxx=0;
    scanf("%lld %lld",&m,&n);
    for(i=0;i<m;i++){
        scanf("%lld",&a[i]);
        maxx=max(a[i],maxx);
    }
    p=1;
    q=maxx*n;
    while(p<q){
        mid=(p+q)/2;
        ans=0;
        for(i=0;i<m;i++){
            ans+=mid/a[i];
        }
        if(ans>=n){
            q=mid;
        }else{
            p=mid+1;
        }
    }
    printf("%lld\n",p);
	return 0;
}
