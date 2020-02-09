/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int u,v,w;
};
A a[100010];
vector<pair<int ,int > > g[100010];
vector<long long > ans;
map<int ,int > mapp[100010];
int qx[100010],order[100010],p[100010];
int findr(int u){
    if(p[u] == u)   return u;
    else            return p[u] = findr(p[u]);
}
void dfs(int now,int pa,int w){
    qx[now] = w;
    for(auto x:g[now]){
        if(x.first == pa)   continue;
        dfs(x.first,now,w^x.second);
    }
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,u,v,w,pu,pv;
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        a[i] = {u,v,w};
    }
    dfs(1,0,0);
    for(int i=1;i<n;i++)
        cin >> order[i];
    for(int i=1;i<=n;i++){
        p[i] = i;
        mapp[i][qx[i]] = 1;
    }
    ans.push_back(0);
    long long sum = 0;
    for(int i=n-1;i>=1;i--){
        pu = findr(a[order[i]].u);
        pv = findr(a[order[i]].v);
        if(mapp[pu].size()>=mapp[pv].size()){
            for(auto x:mapp[pv]){
                // printf("1:%d %d %d\n",x.first,x.second,mapp[pu][x.first]);
                sum+=x.second*mapp[pu][x.first];
                mapp[pu][x.first]+=x.second;
            }
            p[pv] = pu;
        }else{
            for(auto x:mapp[pu]){
                // printf("2:%d %d %d\n",x.first,x.second,mapp[pv][x.first]);
                sum+=x.second*mapp[pv][x.first];
                mapp[pv][x.first]+=x.second;
            }
            p[pu] = pv;
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
        cout << x << '\n';
    return 0;
}
/*
4
1 2 4
2 3 4
2 4 2
3 1 2
*/