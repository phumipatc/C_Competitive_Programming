/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[100010],qs[100010],comp[100010],id[100010];
void update(int idx,long long v){
    while(idx<=100003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
long long query(int idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long n,k,idx;
    scanf("%lld %lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&qs[i]);
        qs[i]+=qs[i-1];
        comp[i] = qs[i];
    }
    sort(comp+1,comp+n+2);
    long long l = -1e11,r = 1e11,mid,countt;
    for(int i=1;i<=n;i++)
        id[i] = lower_bound(comp+1,comp+n+2,qs[i])-comp;
    int idx0 = lower_bound(comp+1,comp+n+2,0)-comp;
    while(l<r){
        mid = (l+r+1)/2,countt = 0;
        update(idx0,1);
        for(int i=1;i<=n;i++){
            idx = upper_bound(comp+1,comp+n+2,qs[i]-mid)-comp-1;
            countt+=query(idx);
            update(id[i],1);
        }
        if(countt>=k)   l = mid;
        else            r = mid-1;
        memset(tree,0,sizeof tree);
    }
    printf("%lld\n",l);
	return 0;
}