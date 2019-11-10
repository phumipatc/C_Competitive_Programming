/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int idx[500010],low[500010],comp[500010];
int mon[500010];
vector<int > g[500010],gp[500010];
int main(){
    int n,m,u,v,group,countt,j;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    group = countt = 1;
    for(int i=1;i<=n;i++){
        if(idx[i])  continue;
    }
	return 0;
}
