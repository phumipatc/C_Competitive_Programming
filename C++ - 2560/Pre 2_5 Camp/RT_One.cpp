/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(a%b==0)  return b;
    else        return gcd(b,a%b);
}
int main(){
    long long q,a,b,ans,temp;
    scanf("%lld",&q);
    while(q--){
        ans=temp=1e18;
        scanf("%lld %lld",&a,&b);
        if(a==1 || b==1){
            printf("1\n");
            continue;
        }
        if(gcd(a,b)!=1){
            printf("NO SOLUTION\n");
            continue;
        }
        for(long long i=1;i<=1000000;i++){
            if((a*i)%b==1){
                ans=i+((a*i)/b);
                break;
            }
        }
        for(long long i=1;i<=1000000;i++){
            if((b*i)%a==1){
                temp=i+((b*i)/a);
                if(temp<ans)    ans=temp;
                break;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
