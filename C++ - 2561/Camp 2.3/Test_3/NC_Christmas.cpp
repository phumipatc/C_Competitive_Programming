/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1200100],dis[1200100];
int main(){
    long long n,sum = 0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<n;i++){
        dis[i] = a[i+1]-a[i];
        sum+=dis[i];
    }
    long long av = (sum/(n-1)),sum2;
    sum = sum2 = 0;
    for(int i=1;i<n;i++){
        sum+=dis[i]-av;
        sum2+=dis[i]-av-1;
    }
    if(abs(sum) == abs(sum2)){
        if(sum<0)   printf("%lld\n%lld\n",av,sum);
        else        printf("%lld\n%lld\n",av+1,sum2);
    }else if(abs(sum)>abs(sum2)){
        if(sum2>=0) printf("%lld\n+%lld\n",av+1,sum2);
        else        printf("%lld\n%lld\n",av+1,sum2);
    }else{
        if(sum>=0)  printf("%lld\n+%lld\n",av,sum);
        else        printf("%lld\n%lld\n",av,sum);
    }
    return 0;
}
