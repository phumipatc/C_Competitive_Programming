/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int now,countt;
};
queue< A> que;
vector< int> g[500100];
int in[500100],a[500100],mark[500100];
int main(){
    int n,m,u,v;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
        in[u]++,in[v]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i]==1 && i!=m)
            que.push({i,0});
    while(!que.empty()){
        A temp=que.front();
        que.pop();
        for(int i=0;i<g[temp.now].size();i++){
            in[g[temp.now][i]]--;
            if(in[g[temp.now][i]]>0 && g[temp.now][i]!=m)
                a[g[temp.now][i]]+=temp.countt+1;
            if(in[g[temp.now][i]]==1 && g[temp.now][i]!=m)
                que.push({g[temp.now][i],a[g[temp.now][i]]});
        }
    }
    if(in[m]>1){
        int ans,maxx=-1;
        for(int i=1;i<=n;i++){
            if(maxx<a[i] && i!=m){
                ans=i;
                maxx=a[i];
            }
        }
        printf("%d\n%d\n",ans,maxx);
    }else{
        int node,ch=0,nextt;
        for(int i=1;i<=n;i++)
            if(in[i]==3)
                node=i;
        que.push({g[node][0],0});
        nextt=g[node][0];
        mark[node]=1;
        while(!que.empty()){
            A temp=que.front();
            que.pop();
            if(temp.now==m){
                ch=1;
                break;
            }
            for(int i=0;i<g[temp.now].size();i++){
                if(!mark[g[temp.now][i]]){
                    mark[g[temp.now][i]]=1;
                    que.push({g[temp.now][i],0});
                }
            }
        }
        while(!que.empty()) que.pop();
        if(!ch)
            for(int i=0;i<g[node].size();i++)
                if(!mark[g[node][i]])
                    nextt=g[node][i];
        if(g[node][0]==nextt)
            que.push({g[node][1],a[g[node][1]]}),in[g[node][1]]--;
        else
            que.push({g[node][0],a[g[node][0]]}),in[g[node][0]]--;
        while(!que.empty()){
            A temp=que.front();
            que.pop();
            for(int i=0;i<g[temp.now].size();i++){
                in[g[temp.now][i]]--;
                if(in[g[temp.now][i]]==1 && g[temp.now][i]!=m){
                    a[g[temp.now][i]]+=temp.countt+1;
                    que.push({g[temp.now][i],a[g[temp.now][i]]});
                }
            }
        }
        int ans,maxx=-1;
        for(int i=1;i<=n;i++){
            if(maxx<a[i] && i!=m){
                maxx=a[i];
                ans=i;
            }
        }
        printf("%d\n%d\n",ans,maxx);
    }
    return 0;
}
