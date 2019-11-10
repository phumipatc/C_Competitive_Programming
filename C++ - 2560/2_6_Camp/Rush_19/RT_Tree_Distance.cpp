/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[50005];
int lv[50005],p[50005],sum[50005];
void dfs(int now,int level){
    lv[now] = level;
    for(int i=0;i<g[now].size();i++){
        if(!lv[g[now][i]]){
            p[g[now][i]] = now;
            sum[g[now][i]] = sum[now]+1;
            dfs(g[now][i],level+1);
        }
    }
}
int main(){
    int n,k,ans = 0,u,v;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sum[1] = 0;
    dfs(1,1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int a = i,b = j,ta = a,tb = b;
            if(lv[a]>lv[b]) swap(a,b);
            while(lv[tb]!=lv[a])
                tb = p[tb];
            while(ta!=tb){
                ta = p[ta];
                tb = p[tb];
            }
            if(sum[a]+sum[b]-sum[ta]-sum[tb] == k)  ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
