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
    long long i,j,n,idx=1,ans,maxx=0,m=0,ch;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        countt[a[i]]++;
        m=max(m,a[i]);
    }
    for(i=1;i<=m;i++){
        ans=ch=0;
        for(j=i;j<=2000000;j+=i){
            if(countt[j]!=0){
                ch+=countt[j];
                ans+=countt[j]*i;
            }
        }
        if(ch>=2)   maxx=max(maxx,ans);
    }
    printf("%lld\n",maxx);
    return 0;
}
