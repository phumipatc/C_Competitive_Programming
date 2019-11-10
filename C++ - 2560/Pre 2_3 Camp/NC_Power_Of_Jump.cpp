/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    long long idx,val;
    bool operator < (const A&o) const{
        if(val!=o.val)  return val<o.val;
        else            return idx>o.idx;
    }
};
A a[5100];
long long num[5100],n,tree[5100][110];
void update(long long power,long long idx,long long val){
    while(idx<=n){
        tree[idx][power]+=val;
        idx+=(idx&(-idx));
    }
}
long long query(long long power,long long idx){
    long long sum=0;
    while(idx>0){
        sum+=tree[idx][power];
        sum%=MOD;
        idx-=(idx&(-idx));
    }
    return sum%MOD;
}
int main(){
    long long q,k;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&k);
        for(long long i=1;i<=n;i++)
            scanf("%lld",&a[i].val),a[i].idx=i;
        sort(a+1,a+n+1);
        for(long long i=1;i<=n;i++)
            num[a[i].idx] = i;
        update(1,num[1],-1);
        update(1,1,1);
        update(0,num[1]+1,1);
        long long temp;
        for(long long i=2;i<n;i++){
            for(long long j=0;j<=k;j++){
                temp = query(j,num[i]);
                update(j,num[i]+1,temp);
            }
            for(long long j=0;j<k;j++){
                temp = query(j,num[i]);
                update(j+1,1,temp);
                update(j+1,num[i],-temp);
            }
        }
        long long ans = 0;
        for(long long i=0;i<=k;i++){
            ans+=query(i,num[n]);
            ans%=MOD;
        }
        printf("%lld\n",ans);
        memset(num,0,sizeof num);
        memset(tree,0,sizeof tree);
    }
    return 0;
}
/*
2
5 0
1
2
3
4
5
5 1
4
5
1
2
3
*/
