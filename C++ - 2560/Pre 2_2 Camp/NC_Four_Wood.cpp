/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[500000];
int main()
{
    long long i,q;
    mic[0]=1;
    for(i=0;i<=100005;i++){
            mic[i+1]+=mic[i];
            mic[i+1]%=100003;
            mic[i+4]+=mic[i];
            mic[i+4]%=100003;
    }
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&i);
        printf("%lld\n",mic[i]);
    }
    return 0;
}
/*
3
3 0
3 1
3 2
*/
