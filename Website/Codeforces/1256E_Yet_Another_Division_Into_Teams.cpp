/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int num,idx;
    bool operator < (const A&o) const{
        if(num!=o.num)  return num<o.num;
        else            return idx<o.idx;
    }
};
A a[200010];
struct B{
    int v,idx;
    bool operator < (const B&o) const{
        return v>o.v;
    }
};
B now;
priority_queue<B > heap;
int dp[200010],warp[200010],ans[200010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].num;
        a[i].idx = i;
    }
    sort(a+1,a+n+1);
    dp[1] = dp[2] = 1e9;
    heap.push({-a[1].num,1});
    for(int i=3;i<=n;i++){
        dp[i] = a[i].num+heap.top().v;
        warp[i] = heap.top().idx;
        // printf("%d %d\n",dp[i],warp[i]);
        heap.push({-a[i-1].num+dp[i-2],i-1});
    }
    int countt = 0,idx = n;
    while(idx>0){
        int temp = idx;
        countt++;
        // printf("%d %d\n",idx,warp[idx]);
        while(idx>=warp[temp]){
            ans[a[idx].idx] = countt;
            idx--;
        }
    }
    printf("%d %d\n",dp[n],countt);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}