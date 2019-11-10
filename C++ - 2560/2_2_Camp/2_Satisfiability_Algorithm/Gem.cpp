/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[400100],inv[400100];
stack< int> s;
int mark[400100],mark2[400100],countt;
void dfs(int u){ 
    mark[u]=1;
    for(int i=0;i<g[u].size();i++)
        if(!mark[g[u][i]])
            dfs(g[u][i]);
    s.push(u);
}
void dfs2(int u){
    mark2[u]=countt;
    for(int i=0;i<inv[u].size();i++)
        if(!mark2[inv[u][i]])
            dfs2(inv[u][i]);
}
int main(){
    int q=5;
    while(q--){
        int ch=0,n,m,i,a,b;
        countt=0;
        memset(mark,0,sizeof mark);
        memset(mark2,0,sizeof mark2);
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            g[(a*2)+1].push_back(b*2);
            g[(b*2)+1].push_back(a*2);
            inv[b*2].push_back((a*2)+1);
            inv[a*2].push_back((b*2)+1);
        }
        for(i=1;i<=m/2;i++){
            scanf("%d %d",&a,&b);
            g[a*2].push_back((b*2)+1);
            g[b*2].push_back((a*2)+1);
            inv[(b*2)+1].push_back(a*2);
            inv[(a*2)+1].push_back(b*2);
        }
        for(i=2;i<2*m;i++)
            if(!mark[i])
                dfs(i);
        while(!s.empty()){
            if(!mark2[s.top()]){
                countt++;
                dfs2(s.top());
            }
            s.pop();
        }
        for(i=1;i<=m;i++)
            if(mark2[2*i]==mark2[(2*i)+1])
                ch=1;
        if(ch)  printf("N");
        else    printf("Y");
        for(i=1;i<=m;i++){
            g[i*2].clear();
            g[(i*2)+1].clear();
            inv[i*2].clear();
            inv[(i*2)+1].clear();
        }
    }
    return 0;
}
/*
4
6
2 3 6 5 3 4 1 2
1 3 2 5 4 6
3
4
1 2 2 3 4 3
1 3 2 4
4
8
1 2 3 4 5 6 7 8
1 3 2 4 5 7 6 8
3
4
1 2 2 3 3 4
2 3 1 4
5
4
1 2 2 3 4 3 1 3 4 2
1 4 2 3
*/
