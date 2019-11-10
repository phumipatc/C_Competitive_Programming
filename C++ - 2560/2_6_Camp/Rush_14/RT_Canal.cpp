/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,val;
};
A maxx[300005];
deque< A> deq;
int a[300005];
int main(){
    int n,k,p = 1e9,q = -1;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p = min(p,a[i]);
        q = max(q,a[i]);
    }
    for(int i=n;i>=0;i--){
        while(!deq.empty() && deq.front().pos>i+k)  deq.pop_front();
        while(!deq.empty() && deq.back().val<a[i] && deq.size()!=1) deq.pop_back();
        deq.push_back({i,a[i]});
        if(i>n-k)   maxx[i] = {n+1,1e9};
        else        maxx[i] = deq.front();
    }
    while(p<q){
        int mid = (p+q+1)/2,now = 0,ch = 1;
        while(now!=n+1){
            if(maxx[now].val<mid){
                ch = 0;
                break;
            }
            now = maxx[now].pos;
        }
        if(ch)  p = mid;
        else    q = mid-1;
    }
    printf("%d\n",p);
    return 0;
}
