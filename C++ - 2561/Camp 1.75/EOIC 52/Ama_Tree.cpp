/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a,b,c;
};
A edge[100100];
vector< A > g[100100];
long long cut[100100],p[100100],qxor[100100];
map<long long,long long> inside[100100];
map<long long,long long>::iterator it;
stack<long long> st;
int fin(long long i){
    if(p[i]==i)return i;
    return p[i]=fin(p[i]);
}
void dfs(long long u,long long p,long long w){
    qxor[u]=w;
    for(auto x:g[u]){
        if(x.a == p)continue;
        dfs(x.a,u,w^x.b);
    }
}
int main(){
    long long n,i,a,b,c,pb,pa,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n-1;i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        g[a].push_back({b,c,0});
        g[b].push_back({a,c,0});
        edge[i]={a,b,c};
    }
    dfs(1,0,0);
    for(i=1;i<=n;i++){
        p[i]=i;inside[i][qxor[i]]=1;
    }
    for(i=1;i<=n-1;i++){
        scanf("%lld",&cut[i]);
    }
    st.push(0);
    for(i=n-1;i>=1;i--){
        a=edge[cut[i]].a,b=edge[cut[i]].b;
        pa=fin(a),pb=fin(b);
        if(inside[pa].size()>inside[pb].size()){
            for(it=inside[pb].begin();it!=inside[pb].end();it++){
                ans+=it->second*inside[pa][it->first];
                inside[pa][it->first]+=it->second;
            }
            p[pb]=pa;
        }else{
            for(it=inside[pa].begin();it!=inside[pa].end();it++){
                ans+=it->second*inside[pb][it->first];
                inside[pb][it->first]+=it->second;
            }
            p[pa]=pb;
        }
        st.push(ans);
    }
    while(!st.empty()){
        printf("%lld\n",st.top());
        st.pop();
    }
    return 0;
}
