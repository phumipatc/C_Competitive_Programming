/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long l,o,v,e,lo,ov,ve,lov,ove,love;
};
A tree[400010],zero,temp;
char a[100010];
A update(A L,A R){
    temp.l = L.l + R.l;
    temp.o = L.o + R.o;
    temp.v = L.v + R.v;
    temp.e = L.e + R.e;
    temp.lo = L.lo + R.lo + (L.l * R.o);
    temp.ov = L.ov + R.ov + (L.o * R.v);
    temp.ve = L.ve + R.ve + (L.v * R.e);
    temp.lov = L.lov + R.lov;
    temp.lov += (L.l * R.ov) + (L.lo * R.v);
    temp.ove = L.ove + R.ove;
    temp.ove += (L.o * R.ve) + (L.ov * R.e);
    temp.love = L.love + R.love;
    temp.love += (L.l * R.ove) + (L.lov * R.e);
    temp.love += (L.lo * R.ve);
    // printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld\n",temp.l,temp.o,temp.v,temp.e,temp.lo,temp.ov,temp.ve,temp.lov,temp.ove,temp.love);
    return temp;
}
void build(long long l,long long r,long long now){
    if(l == r){
        if(a[l] == 'L')         tree[now].l++;
        else if(a[l] == 'O')    tree[now].o++;
        else if(a[l] == 'V')    tree[now].v++;
        else if(a[l] == 'E')    tree[now].e++;
        return ;
    }
    long long mid = (l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    // printf("%lld %lld %lld: ",l,r,now);
    tree[now] = update(tree[now*2],tree[(now*2)+1]);
}
A query(long long l,long long r,long long now,long long ll,long long rr){
    if(rr<l || r<ll)    return zero;
    if(l>=ll && r<=rr)  return tree[now];
    // printf("%lld %lld %lld %lld %lld\n",l,r,now,ll,rr);
    long long mid = (l+r)/2;
    A L = query(l,mid,now*2,ll,rr);
    A R = query(mid+1,r,(now*2)+1,ll,rr);
    return update(L,R);
}
int main(){
    long long n;
    scanf("%lld %s",&n,a+1);
    build(1,n,1);
    long long m,l,r;
    scanf("%lld",&m);
    while(m--){
        scanf("%lld %lld",&l,&r);
        printf("%lld\n",query(1,n,1,l,r).love);
    }
    return 0;
}