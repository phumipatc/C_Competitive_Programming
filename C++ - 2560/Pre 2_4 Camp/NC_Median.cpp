/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[200200],a[100100],mic[100100];
void update(long long idx,long long v){
    while(idx<=200100){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long idx){
    long long sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long n,k,ans=0;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]>=k) mic[i]++;
        else        mic[i]--;
        mic[i]+=mic[i-1];
    }
    update(100001,1);
    for(long long i=1;i<=n;i++){
        ans+=query(mic[i]+100001);
        update(mic[i]+100001,1);
    }
    printf("%lld\n",ans);
    return 0;
}
