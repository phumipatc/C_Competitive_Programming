/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],tree[400010];
set<long long > sett;
set<long long > ::iterator it;
void update(long long l,long long r,long long now,long long idx,long long v){
    if(l>idx || r<idx)  return ;
    if(l == r){
        tree[now] = v;
        return ;
    }
    long long mid = (l+r)/2;
    update(l,mid,now*2,idx,v);
    update(mid+1,r,now*2+1,idx,v);
    tree[now] = max(tree[now*2],tree[now*2+1]);
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        a[i]+=a[i-1];
    }
    sett.insert(n+1);
    update(1,n,1,n,a[n]);
    long long num;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&num);
        it = sett.lower_bound(num);
        // printf("%lld %lld\n",(*it)-1,a[(*it)-1]-a[num]);
        update(1,n,1,(*it)-1,a[(*it)-1]-a[num]);
        if(it!=sett.begin()){
            it--;
            // printf("%lld %lld\n",num-1,a[num-1]-a[*it]);
            update(1,n,1,num-1,a[num-1]-a[*it]);
        }else{
            // printf("%lld %lld\n",num-1,a[num-1]);
            update(1,n,1,num-1,a[num-1]);
        }
        printf("%lld\n",tree[1]);
        sett.insert(num);
    }
	return 0;
}