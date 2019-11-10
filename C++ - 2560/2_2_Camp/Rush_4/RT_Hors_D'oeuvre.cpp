/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
queue< pair<int,int> > q;
int in[100100],ans[100100];
int main(){
    int n,i,u,v,idx=0;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[v].push_back(u);
        in[u]++;
    }
    for(i=1;i<=n;i++)
        if(in[i]==0)
            q.push({make_pair(i,1)});
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(i=0;i<g[a].size();i++){
            in[g[a][i]]--;
            if(g[a][i]==1){
                if(in[g[a][i]]==0)
                    ans[idx++]=b+1;
                else
                    ans[idx++]=b;
                continue;
            }
            if(in[g[a][i]]==0){
                q.push(make_pair(g[a][i],b+1));
            }else{
                ans[idx++]=b;
            }
        }
    }
    sort(ans,ans+idx);
    printf("%d\n",idx);
    for(i=idx-1;i>=0;i--)
        printf("%d\n",ans[i]);
    return 0;
}
