/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[100010],choose[100010][52];
int main(){
    long long n,m,ans = 0;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    choose[0][0] = 1;
    for(long long i=1;i<=n;i++){
        choose[i][0] = 1;
        for(long long j=1;j<=min(m,i);j++){
            choose[i][j] = (choose[i-1][j-1]+choose[i-1][j])%MOD;
        }
    }
    for(long long i=m;i<=n;i++){
        ans = (ans+choose[i-1][m-1]*a[i])%MOD;
    }
    printf("%lld\n",ans);
	return 0;
}
