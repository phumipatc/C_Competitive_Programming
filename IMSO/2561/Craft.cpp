/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long weight[2000010],v[25];
void dp(long long lv,long long w,long long now){
    // printf("%d %d %d\n",lv,w,now);
    weight[now] = w;
    if(lv == 0) return ;
    if(v[lv]%2 == 0){
        dp(lv-1,((2*w)-v[lv]+2)/2,now*2);
        dp(lv-1,((2*w)-v[lv])/2,now*2+1);
    }else{
        dp(lv-1,((2*w)-(v[lv]-1))/2,now*2);
        dp(lv-1,((2*w)-(v[lv]-1))/2,now*2+1);
    }
}
int main(){
    long long n,w;
    scanf("%lld %lld",&n,&w);
    for(long long i=1;i<n;i++)
        scanf("%lld",&v[i]);
    memset(weight,-1,sizeof weight);
    dp(n-1,w,1);
    long long ans = 0;
    for(long long i=(1<<(n-1));i<(1<<n);i++){
        if(weight[i]<=0){
            printf("-1\n");
            return 0;
        }
        ans+=weight[i];
    }
    printf("%lld\n",ans);
    return 0;
}
