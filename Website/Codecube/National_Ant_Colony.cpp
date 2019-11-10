/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
};
vector<A > g[50010];
struct B{
    int u,v,w;
};
B a[70010];
int ant[50010],mark[50010],walk[50010],countt;
void dfs(int now,int lim){
    mark[now] = countt;
    for(auto x:g[now]){
        if(x.w<=lim)    continue;
        if(mark[x.v])   continue;
        dfs(x.v,lim);
    }
}
int main(){
    int n,m,k,u,v,w;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&ant[i]);
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&w);
        a[i] = {u,v,w};
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int l = 0,r = 1e9,mid,ch;
    while(l<r){
        mid = (l+r+1)/2,countt = ch = 1;
        // printf("%d %d %d\n",l,r,mid);
        memset(mark,0,sizeof mark);
        memset(walk,0,sizeof walk);
        for(int i=1;i<=n;i++){
            if(mark[i]) continue;
            dfs(i,mid);
            countt++;
        }
        for(int i=1;i<=n;i++){
            if(walk[ant[i]] == 0) walk[ant[i]] = mark[i];
            else{
                if(walk[ant[i]] == mark[i])   continue;
                ch = 0;
                break;
            }
        }
        if(ch)  l = mid;
        else    r = mid-1;
    }
    countt = 0;
    for(int i=1;i<=m;i++){
        if(a[i].w<=l)
            countt++;
    }
    printf("%d\n",countt);
	return 0;
}
