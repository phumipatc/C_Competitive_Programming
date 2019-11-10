/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long pos,d;
    bool operator < (const A&o)const{
        if(d != o.d)    return d > o.d;
        else if(pos != o.pos)   return pos < o.pos;
        else                    return pos > o.pos;
    }
};
struct B{
    long long pos,dis;
};
priority_queue < A > heap;
vector < B > g[300100];
long long mark[300100],ans[300100],in[300100];
int main(){
    long long q,countt,u,v,i,n,d;
    scanf("%lld",&q);
    while(q--){
        countt = 0;
        scanf("%lld",&n);
        for(i=1;i<n;i++){
            scanf("%lld %lld %lld",&u,&v,&d);
            g[u].push_back({v,d});
            g[v].push_back({u,d});
            in[u]++;
            in[v]++;
        }
        for(i=1;i<=n;i++)
            if(in[i]==1)
                heap.push({i,0});
        while(!heap.empty()){
            A now = heap.top();
            heap.pop();
            if(mark[now.pos])   continue;
            countt++;
            mark[now.pos] = 1;
            for(i=0;i<g[now.pos].size();i++){
                if(mark[g[now.pos][i].pos])   continue;
                in[g[now.pos][i].pos]--;
                ans[g[now.pos][i].pos]=max(ans[g[now.pos][i].pos],now.d+g[now.pos][i].dis);
                if(in[g[now.pos][i].pos]==1 && mark[g[now.pos][i].pos]==0){
                    heap.push({g[now.pos][i].pos,ans[g[now.pos][i].pos]});
                }
            }
            if(countt==n-1){
                for(i=1;i<=n;i++)
                    if(mark[i]==0)
                        break;
                printf("%lld %lld\n",i,ans[i]);
                break;
            }
        }
        while(!heap.empty())   heap.pop();
        memset(ans,0,sizeof ans);
        memset(mark,0,sizeof mark);
        memset(in,0,sizeof in);
        for(i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
/*
1
6
1 2 3
3 4 8
3 5 4
5 6 7
2 3 4
*/
