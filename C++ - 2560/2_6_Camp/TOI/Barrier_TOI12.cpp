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
deque< A> deq;
int a[6000005];
int main(){
    int n,m,maxx = -1,len;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    deq.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(!deq.empty() && deq.front().pos<i-m)  deq.pop_front();
        while(!deq.empty() && deq.back().val>a[i])  deq.pop_back();
        deq.push_back({i,a[i]});
        if(deq.back().val-deq.front().val>maxx){
            maxx = deq.back().val-deq.front().val;
            len = deq.back().pos-deq.front().pos;
        }
        if(deq.back().val-deq.front().val == maxx)
            len = min(len,deq.back().pos-deq.front().pos);
    }
    printf("%d\n%d\n",maxx,len);
    return 0;
}
