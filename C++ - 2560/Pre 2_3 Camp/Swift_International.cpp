/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,num;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A a[50100];
deque< A> deq;
map<int,int> mapp;
int main(){
    long long n,num,all=0,in=0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&a[i].pos,&a[i].num);
        if(mapp[a[i].num]==0)    mapp[a[i].num]=1,all++;
    }
    sort(a+1,a+n+1);
    long long minn=1e9;
    for(long long i=1;i<=n;i++){
        while(!deq.empty() && deq.front().num==a[i].num){
            mapp[deq.front().num]--;
            if(mapp[deq.front().num]==1)    in--;
            deq.pop_front();
        }
        deq.push_back({a[i].pos,a[i].num});
        if(mapp[a[i].num]==1)
            in++;
        mapp[a[i].num]++;
        if(in==all)
            minn=min(minn,deq.back().pos-deq.front().pos+1);
    }
    printf("%lld\n",minn);
    return 0;
}
