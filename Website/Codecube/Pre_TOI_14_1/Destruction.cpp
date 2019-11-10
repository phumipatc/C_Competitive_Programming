/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[2][50001];
long long qs[50001];
int main()
{
    long long n,k,m,i,j,maxx,last,now;
    scanf("%lld %lld %lld",&n,&k,&m);
    for(i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
    }
    maxx=-1e18;
    for(i=m;i<=n;i++){
        maxx=max(maxx,qs[i-m]);
        if(i==m)
            mic[1][i]=qs[i]-maxx;
        else
            mic[1][i]=min(qs[i]-maxx,mic[1][i-1]);
    }
    for(i=2;i<=k;i++){
        maxx=-1e18;
        now=i%2;
        last=(i-1)%2;
        for(j=(i*m)+i-1;j<=n;j++){
            maxx=max(maxx,qs[j-m]-mic[last][j-m-1]);
            if(j==i*m+i-1)  mic[now][j]=qs[j]-maxx;
            else            mic[now][j]=min(qs[j]-maxx,mic[now][j-1]);
        }
    }
    printf("%lld",qs[n]-mic[k%2][n]);
    return 0;
}
