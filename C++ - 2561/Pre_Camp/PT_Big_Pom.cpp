/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long R,S;
vector<long long > bomb;
long long divide(long long l,long long r){
    long long idx;
    idx = upper_bound(bomb.begin(),bomb.end(),r)-bomb.begin();
    idx-= lower_bound(bomb.begin(),bomb.end(),l)-bomb.begin();
    if(l == r){
        if(idx) return S*idx;
        else    return R;
    }
    long long mid = (l+r)/2;
    if(!idx)    return R;
    else        return min(S*(r-l+1)*idx,divide(l,mid)+divide(mid+1,r));
}
int main(){
    long long q,n,c,temp;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld %lld %lld",&n,&c,&R,&S);
        for(long long i=0;i<c;i++){
            scanf("%lld",&temp);
            bomb.push_back(temp);
        }
        sort(bomb.begin(),bomb.end());
        printf("%lld\n",divide(1,1<<n));
        bomb.clear();
    }
	return 0;
}
