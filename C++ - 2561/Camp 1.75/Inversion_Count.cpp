/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[100010],comp[100010],a[100010];
map<long long ,long long > mapp;
void update(long long idx,long long v){
    while(idx<=100005){
        tree[idx]+=v;
        idx+=(idx&(-idx));
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    long long n,num,ans = 1;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
        scanf("%lld",&a[i]);
        comp[i] = a[i];
    }
    sort(comp,comp+n);
    for(long long i=0;i<n;i++)
        if(comp[i]!=comp[i+1])
            mapp[comp[i]] = ans++;
    ans = 0;
    for(long long i=n-1;i>=0;i--){
        ans+=query(mapp[a[i]]-1);
        update(mapp[a[i]],1);
    }
    printf("%lld\n",ans);
	return 0;
}
