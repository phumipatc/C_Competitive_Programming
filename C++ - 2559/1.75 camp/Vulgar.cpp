/*
TASK: Vulgar village
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <vector>
using namespace std;
vector< int> g[60000];
int mark[60000],coun[60000],color[5];
void dfs(int u,int see){
    if(mark[u]) return ;
    mark[u]=1;
    color[see]++;
    for(int i=0;i<coun[u];i++)
        dfs(g[u][i],3-see);
}
int main(){
	int n,m,i,a,b,ans=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        coun[a]++,coun[b]++;
	}
	for(i=1;i<=n;i++){
        if(mark[i]==0){
            color[1]=color[2]=0;
            dfs(i,1);
            if(color[1]>color[2])
                ans+=(color[2]*3)+color[1];
            else
                ans+=(color[1]*3)+color[2];
        }
	}
	printf("%d\n",ans);
	return 0;
}
