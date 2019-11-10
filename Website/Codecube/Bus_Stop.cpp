/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[120000];
long long gcd(long long a,long long b){
  if(a%b==0)
    return b;
  return gcd(b,a%b);
}
int main(){
    long long n,i,sum,g,ans;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)   scanf("%lld",&a[i]);
    ans=a[1];
    for(i=2;i<=n;i++){
        sum=ans*a[i],g=gcd(ans,a[i]);
        ans=sum/g;
    }
    printf("%lld\n",ans);
return 0;
}
