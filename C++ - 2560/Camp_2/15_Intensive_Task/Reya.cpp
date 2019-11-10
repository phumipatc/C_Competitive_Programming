/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,q,i;
    char a[110];
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %lld",a,&m);
        if(strlen(a)>6)         n=m-1;
        else                    sscanf(a,"%llds",&n);
        if(m==1)                printf("0\n");
        else if(n==0 || n==1)   printf("1\n");
        else{
            long long ans=2,sum=1;
            for(i=2;i<=n;i++){
                sum*=i;
                ans+=sum;
                sum%=m,ans%=m;
            }
            printf("%lld\n",ans%m);
        }
    }
    return 0;
}
