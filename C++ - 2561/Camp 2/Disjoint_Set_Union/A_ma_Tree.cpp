/*
    TASK:
    AUTHOR: Phumipat C.
    SCHOOL:RYW
    LANG:C
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a,b,c;
};
A edge[100100];
vector<A> g[100100];
stack<long long> ans;
long long p[100100],qxor[100100],cut[100100];
map<long long,long long> inside[100100];
map<long long,long long>::iterator it;
long long fin(long long i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
void dfs(long long u,long long p,long long w){
    qxor[u]=w;
    for(auto x : g[u]){
        if(x.a==p)  continue;
        dfs(x.a,u,w^x.b);
    }
}
int main()
{
    long long n,i,a,b,c,pa,pb,cnt=0;
    scanf("%lld",&n);
    for(i=1;i<n;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        g[a].push_back({b,c,0});
        g[b].push_back({a,c,0});
        edge[i]={a,b,c};
    }
    dfs(1,0,0);
    for(i=1;i<=n;i++)   p[i]=i,inside[i][qxor[i]]=1;
    for(i=1;i<n;i++)    scanf("%lld",&cut[i]);
    ans.push(0);
    for(i=n-1;i>=1;i--){
        a=edge[ cut[i] ].a,b=edge[ cut[i] ].b;
        pa=fin(a),pb=fin(b);
        if(inside[pa].size()>inside[pb].size()){
            for(it=inside[pb].begin();it!=inside[pb].end();it++){
                cnt += it->second * inside[pa][it->first];
                inside[pa][it->first] += it->second;
            }
            p[pb]=pa;
        }
        else{
            for(it=inside[pa].begin();it!=inside[pa].end();it++){
                cnt += it->second * inside[pb][it->first];
                inside[pb][it->first] += it->second;
            }
            p[pa]=pb;
        }
        ans.push(cnt);
    }
    while(!ans.empty()) {printf("%lld\n",ans.top());ans.pop();}
    return 0;
}
/*
4
1 2 4
2 3 4
2 4 2
3 1 2
*/
