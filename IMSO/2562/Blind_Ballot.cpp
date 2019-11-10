/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int opr,a,b,c;
};
A q[300010];
struct B{
    int v,lvl;
    bool operator < (const B&o) const{
        return lvl>o.lvl;
    }
};
B now;
priority_queue<B > heap;
vector<int > g[20010],ans[20010];
int p[20010],in[20010],lv[20010];
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,ra,rb,rc;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(int i=1;i<=m;i++){
        cin >> q[i].opr >> q[i].a >> q[i].b >> q[i].c;
        if(q[i].opr == 3){
            ra = find_root(q[i].a);
            rb = find_root(q[i].b);
            rc = find_root(q[i].c);
            p[ra] = p[rb] = rc;
        }
    }
    for(int i=1;i<=m;i++){
        if(q[i].opr == 1){
            ra = find_root(q[i].a);
            rb = find_root(q[i].b);
            rc = find_root(q[i].c);
            g[rb].push_back(ra),in[ra]++;
            if(rb!=rc)  g[rc].push_back(ra),in[ra]++;
        }else if(q[i].opr == 2){
            ra = find_root(q[i].a);
            rb = find_root(q[i].b);
            rc = find_root(q[i].c);
            g[ra].push_back(rb),in[rb]++;
            if(rb!=rc)  g[ra].push_back(rc),in[rc]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        heap.push({i,1});
    }
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        lv[now.v] = now.lvl;
        for(auto x:g[now.v]){
            in[x]--;
            if(in[x])   continue;
            heap.push({x,now.lvl+1});
        }
    }
    for(int i=1;i<=n;i++)
        ans[lv[find_root(i)]].push_back(i);
    int countt = 0;
    for(int i=1;i<=n;i++){
        if(!ans[i].size())  break;
        countt++;
    }
    printf("%d\n",countt);
    for(int i=1;i<=n;i++){
        if(!ans[i].size())  break;
        printf("%d ",ans[i].size());
        for(auto x:ans[i])
            printf("%d ",x);
        printf("\n");
    }
    return 0;
}