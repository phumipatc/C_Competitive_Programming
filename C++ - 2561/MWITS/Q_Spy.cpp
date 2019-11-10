/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
int p[1010];
int fr(int i){
    if(p[i] == i)   return i;
    else            return p[i] = fr(p[i]);
}
int main(){
    int n,temp,ru,rv;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        p[i] = i;
        for(int j=1;j<=n;j++){
            scanf("%d",&temp);
            heap.push({i,j,temp});
        }
    }
    p[n+1] = n+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        heap.push({i,n+1,temp});
    }
    int ans = 0;
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        ru = fr(now.u);
        rv = fr(now.v);
        if(ru == rv)    continue;
        ans+=now.w;
        p[ru] = rv;
    }
    printf("%d\n",ans);
	return 0;
}
