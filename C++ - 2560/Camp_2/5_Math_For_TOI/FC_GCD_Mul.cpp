/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long num[1200][1200],a[1200],b[1200];
long long gcd(long long a,long long b){
    if(a%b==0)  return b;
    return gcd(b,a%b);
}
int main()
{
    long long n,m,i,j,ch=0,ans=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    scanf("%lld",&m);
    for(i=1;i<=m;i++){
        scanf("%lld",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    //printf("hi\n");
    for(j=1;j<=n;j++){
        for(i=1;i<=m;i++){
            num[i][j]=gcd(a[j],b[i]);
            a[j]/=num[i][j];
            b[i]/=num[i][j];
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            ans*=num[i][j];
            if(ans>=1000000000) ch=1;
            ans%=1000000000;
        }
    }
    /*
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("%lld ",num[i][j]);
        }
        printf("\n");
    }
    */
    if(ch)
        printf("%09lld\n",ans);
    else
        printf("%lld\n",ans);
    return 0;
}
/*
3
4 6 5
7
6 7 3 9 2 13 58
*/
