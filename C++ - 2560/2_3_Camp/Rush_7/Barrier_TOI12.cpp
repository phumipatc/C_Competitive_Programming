/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,val;
};
int a[6000100];
deque< A> deq;
int main(){
    int n,w;
    scanf("%d %d",&n,&w);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    int maxx=-1e9,len;
    deq.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(!deq.empty() && deq.front().idx<i-w) deq.pop_front();
        while(!deq.empty() && deq.back().val>a[i])  deq.pop_back();
        deq.push_back({i,a[i]});
        if(deq.back().val-deq.front().val>maxx){
            maxx=deq.back().val-deq.front().val;
            len=deq.back().idx-deq.front().idx;
        }
        if(deq.back().val-deq.front().val==maxx)
            len=min(len,deq.back().idx-deq.front().idx);
    }
    if(maxx<0)  printf("0\n0\n");
    else        printf("%d\n%d\n",maxx,len);
    return 0;
}
