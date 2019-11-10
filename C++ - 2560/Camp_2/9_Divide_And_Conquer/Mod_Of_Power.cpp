/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mod(int a,int b,int c){
    if(b==0)    return 1;
    if(b==1)    return a%c;
    long long p=mod(a,b/2,c);
    if(b%2==0)  return (p*p)%c;
    else        return (p*p*a)%c;
}
int main()
{
    int q,a,b,c;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        printf("%lld\n",mod(a,b,c));
    }
    return 0;
}
