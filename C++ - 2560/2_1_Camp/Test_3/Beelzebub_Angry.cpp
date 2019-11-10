/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100100],b[100100];
int main(){
    long long n,m,i,sum=0;
    long long ans=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+m+1);
    sum-=n;
    if(sum<=0){
        printf("0\n");
        return 0;
    }
    for(i=1;i<=m;i++){
        if(sum/(m-i+1)<=a[i])   b[i]=sum/(m-i+1),sum-=sum/(m-i+1);
        else                    b[i]=a[i],sum-=a[i];
    }
    for(i=1;i<=m&&sum>0;i++)
        if(b[i]+1<=a[i])
            b[i]++,sum--;
    for(i=1;i<=m;i++)
        ans += b[i]*b[i];
    printf("%lld\n",ans);
    return 0;
}
