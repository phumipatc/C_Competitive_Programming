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
    int n;
    long long ans=0;
    scanf("%d",&n);
    if(n>=9){
        ans+=3000*(n/15);
        n%=15;
        if(n>=9){
            ans+=3000;
            n-=n;
        }
    }
    if(n>=4){
        ans+=1500*(n/5);
        n%=5;
        if(n>=4){
            ans+=1500;
            n-=n;
        }
    }
    if(n>=2){
        ans+=800*(n/2);
        n%=2;
    }
    if(n==1){
        ans+=500*(n);
    }
    printf("%lld\n",ans);
    return 0;
}
