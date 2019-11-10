/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,c,d;
    scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&c,&d);
    long long minn=min(a+b,min(a+c,min(b+d,c+d)));
    long long maxx=max(a+b,max(a+c,max(b+d,c+d)));
    long long need=maxx-minn+1;
    if(n-need+1<=0) printf("0\n");
    else{
        long long ans=(n-need+1)*n;
        printf("%lld\n",ans);
    }
    return 0;
}
