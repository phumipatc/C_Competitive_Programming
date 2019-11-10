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
int deg[1010],p[1010];
int fr(int i){
    if(i == p[i])   return i;
    else            return p[i] = fr(p[i]);
}
int main(){
    int q,n,temp,ru,rv;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            p[i] = i;
            for(int j=1;j<=n;j++){
                scanf("%d",&temp);
                if(j<=i)    continue;
                heap.push({i,j,temp});
            }
        }
        while(!heap.empty()){
            now = heap.top();
            heap.pop();
            ru = fr(now.u);
            rv = fr(now.v);
            if(ru == rv)    continue;
            p[ru] = rv;
            deg[now.u]++,deg[now.v]++;
        }
        int maxx = 0,ans;
        for(int i=1;i<=n;i++){
            if(maxx<deg[i]){
                maxx = deg[i];
                ans = i;
            }
        }
        printf("%d %d\n",ans,maxx);
        memset(deg,0,sizeof deg);
    }
	return 0;
}
