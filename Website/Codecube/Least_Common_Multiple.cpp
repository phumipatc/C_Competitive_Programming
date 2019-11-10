/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
  if(a%b==0)    return b;
  return gcd(b,a%b);
}
int main(){
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",abs((a*b)/gcd(a,b)));
return 0;
}
