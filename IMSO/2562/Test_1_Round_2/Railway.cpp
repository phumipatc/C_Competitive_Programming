/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int ma[200010];
struct A{
    int u,v,w,idx;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return ma[idx]<ma[o.idx];
    }
};
set<A > sett;
set<A > ::iterator it,it2;
vector<pair<int ,int > > g[100010];
int LCA[100010][18],mw[100010][18],lv[100010],weight[200010];
void dfs(int u,int pa,int w,int state){
    // printf("processing: %d %d %d %d\n",u,pa,w,state);
    LCA[u][0] = pa;
    lv[u] = state;
    mw[u][0] = w;
    for(int i=1;i<18;i++){
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
        mw[u][i] = max(mw[u][i-1],mw[LCA[u][i-1]][i-1]);
    }
    for(auto x:g[u]){
        if(x.first == pa)   continue;
        dfs(x.first,u,x.second,state+1);
    }
}
int maxx;
void find_LCA(int u,int v){
    if(lv[u]>lv[v]) swap(u,v);
    for(int i=16;i>=0;i--){
        if(lv[LCA[v][i]]<lv[u]) continue;
        maxx = max(maxx,mw[v][i]);
        v = LCA[v][i];
    }
    if(u == v)  return ;
    for(int i=16;i>=0;i--){
        if(LCA[u][i] == LCA[v][i])  continue;
        maxx = max(maxx,mw[u][i]);
        maxx = max(maxx,mw[v][i]);
        u = LCA[u][i];
        v = LCA[v][i];
    }
    maxx = max(maxx,mw[u][0]);
    maxx = max(maxx,mw[v][0]);
}
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        if(u>v) swap(u,v);
        if(i<n){
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            continue;
        }
        if(i == n)  dfs(1,0,0,1);
        weight[i] = w;
        maxx = 0;
        find_LCA(u,v);
        ma[i] = maxx;
        sett.insert({u,v,w,i});
    }
    int ans = 1;
    while(!sett.empty()){
        it = sett.begin();
        sett.erase(it);
        maxx = ma[it->idx];
        if(maxx<it->w)  continue;
        it2 = sett.lower_bound({0,0,maxx+1,0});
        if(it2 == sett.end()){
            ans = 0;
            break;
        }
        swap(weight[it->idx],weight[it2->idx]);
        sett.erase(it2);
        sett.insert({it2->u,it2->v,it->w,it2->idx});
    }
    printf("%d\n",ans);
    if(ans){
        for(int i=n;i<=m;i++)
            printf("%d\n",weight[i]);
    }
    return 0;
}