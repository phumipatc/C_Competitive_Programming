/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0)  return b;
    else        return gcd(b,a%b);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n",m-gcd(n,m));
    return 0;
}
