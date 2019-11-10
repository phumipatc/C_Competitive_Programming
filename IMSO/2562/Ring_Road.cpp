/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w,k;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
priority_queue<A > heap;
vector<A > g[200010];
int ring[200010],dis[200010],head[200010],tree[200010];
void update(int idx,int v){
    while(idx<=200003){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,k,q,opr,u,v,w;
    scanf("%d %d %d",&n,&k,&q);
    for(int i=1;i<=k;i++)
        scanf("%d",&ring[i]);
    for(int i=1;i<=n-k;i++){
        scanf("%d %d",&v,&w);
        g[v].push_back({i+k,w});
    }
    for(int i=k+1;i<=n;i++)
        dis[i] = 1e9;
    for(int i=1;i<=k;i++)
        heap.push({i,0,i});
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        dis[now.v] = now.w;
        head[now.v] = now.k;
        for(auto x:g[now.v])
            heap.push({x.v,x.w+now.w,now.k});
    }
    for(int i=1;i<k;i++)
        update(i,ring[i]);
    while(q--){
        scanf("%d %d %d",&opr,&u,&v);
        if(opr == 0){
            if(u!=k)    update(u,v-ring[u]);
            ring[u] = v;
        }else{
            if(u>k && v>k){
                if(head[u] == head[v]){
                    printf("%d\n",abs(dis[u]-dis[v]));
                    continue;
                }
                int ans = dis[u]+dis[v];
                u = head[u],v = head[v];
                if(u>v) swap(u,v);
                ans+=min(query(v-1)-query(u-1),ring[k]+query(u-1)+(query(k)-query(v-1)));
                printf("%d\n",ans);
            }else if(u<=k && v<=k){
                if(u>v) swap(u,v);
                printf("%d\n",min(query(v-1)-query(u-1),ring[k]+query(u-1)+(query(k)-query(v-1))));
            }else{
                int ans = dis[u]+dis[v];
                u = head[u],v = head[v];
                if(u>v) swap(u,v);
                ans+=min(query(v-1)-query(u-1),ring[k]+query(u-1)+(query(k)-query(v-1)));
                printf("%d\n",ans);
            }
        }
    }
	return 0;
}
/*
6 3 5
1
1
1
1 2
3 3
4 2
1 2 5
1 5 6
0 3 10
1 4 5
1 2 1
*/