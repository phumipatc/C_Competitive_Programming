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
    long long n,sum=0;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=2;i<=n;i++){
        dis[i-1]=a[i]-a[i-1];
        sum+=dis[i-1];
    }
    long long ans1=(sum/(n-1)),sum2=0;
    sum=0;
    for(int i=1;i<n;i++){
//        printf("%lld\n",dis[i]-ans1);
        sum+=dis[i]-ans1;
        sum2+=dis[i]-ans1-1;
    }
    if(abs(sum)==abs(sum2)){
        if(sum<0)   printf("%lld\n%lld\n",ans1,sum);
        else        printf("%lld\n%lld\n",ans1+1,sum2);
    }else if(abs(sum)>abs(sum2)){
        if(sum2>=0)
            printf("%lld\n+%lld\n",ans1+1,sum2);
        else
            printf("%lld\n%lld\n",ans1+1,sum2);
    }else{
        if(sum>=0)
            printf("%lld\n+%lld\n",ans1,sum);
        else
            printf("%lld\n%lld\n",ans1,sum);
    }
    return 0;
}
