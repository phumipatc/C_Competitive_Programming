/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
    bool operator < (const A&o) const{
        if(l!=o.l)  return l<o.l;
        else        return r>o.r;
    }
};
vector<A > v;
int LIS[100010];
int main(){
    int n,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l,&r);
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    int maxx = 0;
    for(auto x:v){
        int idx = upper_bound(LIS,LIS+maxx,-x.r)-LIS;
        if(idx == maxx)
            maxx++;
        LIS[idx] = -x.r;
    }
    printf("%d\n",maxx);
	return 0;
}