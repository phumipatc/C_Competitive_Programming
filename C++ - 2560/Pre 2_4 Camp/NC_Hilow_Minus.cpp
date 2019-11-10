/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int val,idx;
};
deque<A> deq;
int a[1000010],b[1000010],c[1000010];
int main(){
    int n,m,i,ans=1e9;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(i=0;i<n;i++)
        b[i] = abs(a[i+1]-a[i]);
    int idx = 1;
    for(i=1;i<=n-1;i++){
        while(!deq.empty() && i-deq.front().idx>=n-m)   deq.pop_front();
        while(!deq.empty() && b[i]<deq.back().val)      deq.pop_back();
        deq.push_back({b[i],i});
        if(i>=n-m-1)
            c[idx++] = deq.front().val;
    }
    for(i=1;i<=m+1;i++)
        ans = min(ans,c[i]+abs(a[i]-a[i+n-m-1]));
    printf("%d\n",ans);
    return 0;
}
/*
6 2
9 7 -4 1 12 -2
*/

