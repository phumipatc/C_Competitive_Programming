#include<bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&n);
        if(n >= 900202009){
            printf("%lld\n",n-128);
        }
        else{
            long long k = ((900202009-n)/1881) + ((900202009-n)%1881!=0);
            printf("%lld\n",n+((1881)*k)-128);
        }
    }

    return 0;
}


