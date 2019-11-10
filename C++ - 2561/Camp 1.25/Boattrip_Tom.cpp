/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long st,en;
    bool operator < (const A&o) const{
        if(st!=o.st)    return st<o.st;
        else            return en<o.en;
    }
};
vector< A> v;
int main(){
    long long a,b,st,en,ans = 0;
    scanf("%lld %lld",&a,&b);
    for(long long i=1;i<=a;i++){
        scanf("%lld %lld",&st,&en);
        if(st<en)   continue;
        v.push_back({en,st});
    }
    st = en = 0;
    sort(v.begin(),v.end());
    for(long long i=0;i<v.size();i++){
        if(v[i].st<=en) en = max(en,v[i].en);
        else{
            ans+=en-st;
            st = v[i].st,en = v[i].en;
        }
    }
    ans+=en-st;
    printf("%lld\n",b+(2*ans));
	return 0;
}
