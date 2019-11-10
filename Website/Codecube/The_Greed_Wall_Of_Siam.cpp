/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long x[120000],ans[120000],answer=0;
long long gcd(long long a,long long b){
  if(a==0)
    return b;
  return gcd(b%a,a);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&x[i]);
    ans[0]=x[0];
    for(i=1;i<n;i++){
        ans[i]=gcd(ans[i-1],x[i]);
        if(ans[i]!=ans[i-1] && i!=1)
            ans[i]=gcd(x[i],x[i-2]);
    }
    for(i=0;i<n;i++){
        answer+=(x[i]/ans[n-1]);
    }
    printf("%lld",answer);
return 0;
}
