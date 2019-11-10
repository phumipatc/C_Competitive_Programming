/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],in[1010],mark[1010];
vector<int> g[1010];
long long sum,j;
void dfs(int u){
    if(mark[u]==j)  return ;
    mark[u]=j;
    sum+=a[u];
    for(int i=0;i<g[u].size();i++)
        dfs(g[u][i]);
}
int main()
{
    int n,m,i,r,s,maxx=-1,ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<m;i++){
        scanf("%d %d",&r,&s);
        g[r].push_back(s);
        in[s]++;
    }
    for(j=1;j<=n;j++){
        if(in[j]==0){
            sum=0;
            dfs(j);
            if(sum>maxx)
                maxx=sum,ans=j;
        }
    }
    printf("%d %d\n",ans,maxx);
    return 0;
}
