/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long s,k;
    bool operator < (const A&o) const{
        if(s!=o.s)  return s>o.s;
        else        return k<o.k;
    }
};
A p[100005];
long long LIS[100005];
int main(){
    long long q,maxx,n,idx;
    scanf("%d",&q);
    while(q--){
        maxx = 0;
        scanf("%d",&n);
        for(long long i=0;i<n;i++)
            scanf("%d %d",&p[i].s,&p[i].k);
        sort(p,p+n);
        for(long long i=0;i<n;i++){
            idx = upper_bound(LIS,LIS+maxx,p[i].k)-LIS;
            if(idx == maxx) maxx++;
            LIS[idx] = p[i].k;
        }
        printf("%d\n",maxx);
    }
    return 0;
}
