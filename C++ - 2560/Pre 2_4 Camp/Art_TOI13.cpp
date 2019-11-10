/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,h,v;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A line[200200];
long long fw[1000100];
void update(long long idx,long long v){
    while(idx<=1000000){
        fw[idx]+=v;
        idx+=(idx&-idx);
    }
}
long long query(long long idx){
    long long sum=0;
    while(idx>0){
        sum+=fw[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    long long i,j,n,a,b,c,d,st,en,l,r,mid;
    long long ans=0,temp,t;
    scanf("%lld %lld",&n,&t);
    for(i=0;i<n;i++){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        line[2*i]={a,b,d};
        line[2*i+1]={a+c,b,-d};
    }
    sort(line,line+2*n);
    line[2*n]={4000001,0,0};
    for(i=0;i<2*n;i++){
        for(j=i;line[j].pos==line[j+1].pos;j++){
            update(1,line[j].v);
            update(line[j].h+1,-line[j].v);
        }
        update(1,line[j].v);
        update(line[j].h+1,-line[j].v);
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            temp=query(mid);
            if(temp>t)  l=mid+1;
            else        r=mid;
        }
        st=l;
        l=1,r=1000000;
        while(l<r){
            mid=(l+r)/2;
            temp=query(mid);
            if(temp>=t)  l=mid+1;
            else        r=mid;
        }
        en=l;
        ans+=(long long)(en-st)*(long long)(line[j+1].pos-line[j].pos);
        i=j;
    }
    printf("%lld\n",ans);
    return 0;
}
