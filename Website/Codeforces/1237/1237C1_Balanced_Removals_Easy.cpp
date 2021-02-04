/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,z,num;
};
A a[2010];
long long dist(A a,A b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int main(){
    long long n,minn,idx;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].z),a[i].num = i;
    for(long long i=1;i<=n;i+=2){
        minn = 1e18;
        for(long long j=i+1;j<=n;j++){
            if(minn>dist(a[i],a[j])){
                minn = dist(a[i],a[j]);
                idx = j;
            }
        }
        swap(a[i+1],a[idx]);
        printf("%lld %lld\n",a[i].num,a[i+1].num);
    }
    return 0;
}