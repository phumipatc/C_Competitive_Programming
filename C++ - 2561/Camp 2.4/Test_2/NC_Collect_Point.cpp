/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
set<long long > sett;
set<long long > ::iterator it;
int main(){
    long long n,m,sum = 0,maxx = -1,num;
    scanf("%lld %lld",&n,&m);
    sett.insert(0);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        sum+=num;
        sum%=m;
        maxx = max(maxx,sum);
        it = sett.lower_bound(sum+1);
        maxx = max(maxx,(sum+m-(*it))%m);
        sett.insert(sum);
    }
    printf("%lld\n",maxx);
    return 0;
}
