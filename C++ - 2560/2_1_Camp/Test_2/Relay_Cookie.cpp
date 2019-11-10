/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,k;
};
int mark[100100],candy[100100];
vector< int> g[100100];
queue< A> q;
int main()
{
    int n,k;
    cin >> n >> k;
    for(int i=1;i<n;i++){
        int s,e;
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    for(int i=1;i<=n;i++)
        cin >> candy[i];
    for(int i=1;i<=n;i++){
        memset(mark,0,sizeof mark);
        int ans=0;
        q.push({i,0});
        mark[i]=1;
        while(!q.empty()){
            A temp=q.front();
            q.pop();
            ans+=candy[temp.v];
            if(temp.k+1>k)  continue;
            for(int j=0;j<g[temp.v].size();j++){
                if(mark[g[temp.v][j]]==0){
                    mark[g[temp.v][j]]=1;
                    q.push({g[temp.v][j],temp.k+1});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
6 2
1 2
1 5
2 3
2 4
3 6
1
2
3
4
5
6
*/
