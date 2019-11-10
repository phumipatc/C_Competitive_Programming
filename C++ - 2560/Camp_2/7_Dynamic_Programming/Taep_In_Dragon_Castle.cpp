/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[30][30],b[30][30];
int main()
{
    long long q,r,c,k,p,j,i;
    scanf("%lld",&q);
    while(q--){
        long long sum=0;
        scanf("%lld %lld %lld %lld",&r,&c,&k,&p);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                b[i][j]=1;
        while(--k){
            for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                    mic[i][j]=(b[i][j]+b[i-1][j]+b[i+1][j]+b[i][j-1]+b[i][j+1])%p;
            for(i=1;i<=r;i++)
                for(j=1;j<=c;j++)
                    b[i][j]=(mic[i][j])%p;
        }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                sum+=b[i][j];
        printf("%lld\n",sum%p);
        memset(b,0,sizeof b);
    }
    return 0;
}
