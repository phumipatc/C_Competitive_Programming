/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,h,w;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos<o.pos;
        else            return w<o.w;
    }
};
A a[200010];
long long tree[1000010];
void update(long long idx,long long v){
    while(idx<=1000003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
long long query(long long idx){
    long long sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    long long n,t,st,h,w,v,ans = 0,temp,maxx = 0;
    scanf("%lld %lld",&n,&t);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld %lld %lld",&st,&h,&w,&v);
        a[i].pos = st,a[i].h = h,a[i].w = v;
        a[i+n].pos = st+w,a[i+n].h = h,a[i+n].w = -v;
        maxx = max(maxx,a[i].h);
    }
    sort(a+1,a+(2*n)+1);
    long long l,r,mid,num,ch,idx1,idx2;
    for(long long i=1;i<=2*n;i++){
        l = 1,r = maxx,ch = 0;
        if(a[i].pos == a[i-1].pos)  goto jump;
        while(l<=r){
            mid = (l+r)/2;
            num = query(mid);
            // printf("%lld %lld\n",mid,num);
            if(num>t)       l = mid+1;
            else if(num<t)  r = mid-1;
            else{
                ch = 1;
                break;
            }
        }
        if(ch){
            idx1 = mid;
            l = mid,r = maxx;
            while(l<r){
                mid = (l+r+1)/2;
                num = query(mid);
                if(num == t)    l = mid;
                else            r = mid-1;
            }
            idx2 = l;
            l = 1,r = idx1;
            while(l<r){
                mid = (l+r)/2;
                num = query(mid);
                if(num == t)    r = mid;
                else            l = mid+1;
            }
            idx1 = l;
            ans+=(idx2-idx1+1)*(a[i].pos-a[i-1].pos);
        }
        jump:;
        update(1,a[i].w);
        update(1+a[i].h,-a[i].w);
    }
    printf("%lld\n",ans);
	return 0;
}
