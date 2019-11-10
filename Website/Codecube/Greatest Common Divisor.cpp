/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  if(a==0)
    return b;
  return gcd(b%a,a);
}
int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",gcd(a,b));
return 0;
}
