/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long x[500100],y[500100];
int main(){
    long long n,ans=0,sum=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lld %lld",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    for(int i=0;i<n;i++){
        ans+=(x[i]*i)-sum;
        sum+=x[i];
    }
    sum=0;
    for(int i=0;i<n;i++){
        ans+=(y[i]*i)-sum;
        sum+=y[i];
    }
    printf("%lld\n",ans);
    return 0;
}
