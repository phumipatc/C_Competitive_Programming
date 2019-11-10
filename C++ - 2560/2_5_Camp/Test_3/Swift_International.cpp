/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,from;
    bool operator < (const A&o) const{
        return pos<o.pos;
    }
};
A a[50005];
deque< A> deq;
map<int,int> mapp;
int main(){
    int n,pos,from,all = 0,now = 0,ans = 1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].pos,&a[i].from);
        if(!mapp[a[i].from])    mapp[a[i].from]++,all++;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        while(!deq.empty() && deq.front().from == a[i].from){
            mapp[deq.front().from]--;
            if(mapp[deq.front().from] == 1) now--;
            deq.pop_front();
        }
        deq.push_back({a[i].pos,a[i].from});
        if(mapp[a[i].from] == 1)    now++;
        mapp[a[i].from]++;
        if(now == all)
            ans = min(ans,deq.back().pos-deq.front().pos+1);
    }
    printf("%d\n",ans);
    return 0;
}
