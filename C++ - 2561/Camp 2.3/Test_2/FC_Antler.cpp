/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200100],countt[2000100];
int main(){
    long long i,j,n,idx = 1,sum,ans = 0,maxx = 0,ch;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        countt[a[i]]++;
        maxx = max(maxx,a[i]);
    }
    for(i=1;i<=maxx;i++){
        sum = ch = 0;
        for(j=i;j<=2000000;j+=i){
            if(countt[j]!=0){
                ch+=countt[j];
                sum+=countt[j]*i;
            }
        }
        if(ch>=2)   ans=max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}
