/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[200100],comp[200100],tree[200100];
void update(int idx,int v){
    while(idx<=200010){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(int idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long q,idx,n,now;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(long long i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            comp[i-1] = a[i];
        }
        sort(comp,comp+n);
        idx = 0;
        comp[n] = 1e18;
        for(long long i=0;i<n;i++)
            if(comp[i]!=comp[i+1])
                comp[idx++] = comp[i];
        long long ans = 0;
        for(long long i=1;i<=n;i++){
            now = upper_bound(comp,comp+idx,a[i])-comp;
            ans+=(query(idx)-query(now-1));
            update(now,1);
        }
        printf("%lld\n",ans);
        memset(tree,0,sizeof tree);

    }
    return 0;
}
