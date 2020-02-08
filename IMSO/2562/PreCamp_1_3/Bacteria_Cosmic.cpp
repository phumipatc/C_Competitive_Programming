/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y,num;
};
A a[100010];
struct B{
    long long pos,num,st;
    bool operator < (const B&o) const{
        return pos<o.pos;
    }
};
set<B > sett;
set<B > ::iterator idx,nextt,last,x;
long long dis(A a,A b){
    return abs(a.x-b.x)+abs(a.y-b.y)+a.num;
}
long long countt[100010];
int main(){
    long long n,L,l,r,mid,now,st,en;
    scanf("%lld %lld",&n,&L);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y),a[i].num = i;
    sett.insert({L,1,0});
    for(long long i=2;i<=n;i++){
        //lower_bound
        l = 0,r = a[i].x;
        while(l<r){
            mid = (l+r)/2;
            now = sett.lower_bound({mid,0,0})->num;
            if(dis(a[now],{mid,0})<=dis(a[i],{mid,0}))  l = mid+1;
            else                                        r = mid;
        }
        st = l;
        //upper_bound
        l = a[i].x,r = L;
        while(l<r){
            mid = (l+r+1)/2;
            now = sett.lower_bound({mid,0,0})->num;
            if(dis(a[now],{mid,0})<=dis(a[i],{mid,0}))  r = mid-1;
            else                                        l = mid;
        }
        en = l;
        // printf("%lld %lld\n",st,en);
        idx = sett.lower_bound({st,0,0});
        if(st == en)
            if(dis(a[idx->num],{st,0})<=dis(a[i],{st,0}))
                continue;
        nextt = idx;
        while(idx!=sett.end() && idx->pos<=en){
            nextt = idx;
            nextt++;
            sett.erase(idx);
            if(idx->st<st)  sett.insert({st-1,idx->num,idx->st});
            idx = nextt;
        }
        sett.insert({en,i,st});
    }
    for(x=sett.begin();x!=sett.end();x++){
        // printf("%lld %lld\n",i->num,i->pos);
        if(x == sett.begin())   countt[x->num] = (x->pos)+1;
        else{
            last = x;
            last--;
            countt[x->num] = (x->pos)-(last->pos);
        }
    }
    for(long long i=1;i<=n;i++)
        printf("%lld\n",countt[i]);
	return 0;
}