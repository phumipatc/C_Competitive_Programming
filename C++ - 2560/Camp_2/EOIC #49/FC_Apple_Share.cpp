/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)  return b;
    return gcd(b,a%b);
}
int main()
{
    int n,m,i,a;
    scanf("%d %d",&n,&m);
    a=gcd(n,m);
    for(i=1;i<=a;i++){
        if(a%i==0){
            printf("%d %d %d\n",i,n/i,m/i);
        }
    }
    return 0;
}
