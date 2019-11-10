/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[1100];
int mark[1100];
queue<int> que;
int main()
{
    int temp,q,n,m,k,i,j,a,b,countt;
    scanf("%d",&q);
    while(q--){
        countt=0;
        memset(mark,0,sizeof mark);
        scanf("%d %d %d",&n,&m,&k);
        while(!que.empty()) que.pop();
        for(i=1;i<=n;i++)
            g[i].clear();
        for(i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(i=0;i<k;i++){
            scanf("%d",&a);
            mark[a]=1;
            que.push(a);
        }
        while(!que.empty()){
            temp=que.front();
            que.pop();
            for(i=0;i<g[temp].size();i++)
                mark[g[temp][i]]=1;
        }
        for(i=1;i<=n;i++)
            if(mark[i]) countt++;
        printf("%d\n",countt);
    }
    return 0;
}
