/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[200010],fact[200010];
map<int ,int > mapp[200010];
int a[200010],ans = 0;
void dfs(int now,int p){
    for(auto x:g[now]){
        if(x == p)  continue;
        dfs(x,now);
    }
    int maxx1,maxx2;
    for(auto comp:fact[a[now]]){
        mapp[now][comp] = 1;
        maxx1 = maxx2 = 0;
        for(auto x:g[now]){
            if(x == p)  continue;
            if(mapp[x][comp]>=maxx1)        maxx2 = maxx1,maxx1 = mapp[x][comp];
            else if(mapp[x][comp]>maxx2)    maxx2 = mapp[x][comp];
        }
        ans = max(ans,maxx1+maxx2+mapp[now][comp]);
        mapp[now][comp]+=maxx1;
    }
}
int main(){
    int n,u,v;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=2;i<=200000;i++){
        if(fact[i].size())  continue;
        for(int j=i;j<=200000;j+=i)
            fact[j].push_back(i);
    }
    dfs(1,0);
    printf("%d\n",ans);
	return 0;
}
