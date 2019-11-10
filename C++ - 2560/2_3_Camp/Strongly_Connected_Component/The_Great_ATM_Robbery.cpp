/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long idx,loop;
};
A now;
stack< A> dfs;
stack< long long> s;
vector< long long> g1[500100],inv[500100],g2[500100];
long long money[500100],component_num[500100];
long long pub[500100],mark[500100],value[500100];
long long stop[500100],mic[500100];
void DFS(long long now){
    for(long long i=0;i<g2[now].size();i++){
        if(!mark[g2[now][i]]){
            mark[g2[now][i]]=1;
            DFS(g2[now][i]);
        }else{
            if(mic[g2[now][i]]==-1 && stop[now]==1)
                mic[now]=max(mic[now],value[now]);
            else if(mic[g2[now][i]]!=-1)
                mic[now]=max(mic[now],value[now]+mic[g2[now][i]]);
        }
        if(mic[g2[now][i]]==-1 && stop[now]==1)
                mic[now]=max(mic[now],value[now]);
            else if(mic[g2[now][i]]!=-1)
                mic[now]=max(mic[now],value[now]+mic[g2[now][i]]);
    }
    if(stop[now]==1)
        mic[now]=max(mic[now],value[now]);
}
int main(){
    long long n,m,u,v;
    scanf("%lld %lld",&n,&m);
    for(long long i=1;i<=m;i++){
        scanf("%lld %lld",&u,&v);
        g1[u].push_back(v);
        inv[v].push_back(u);
    }
    for(long long i=1;i<=n;i++)
        scanf("%lld",&money[i]);
    long long st,p;
    scanf("%lld %lld",&st,&p);
    for(long long i=1;i<=p;i++){
        scanf("%lld",&u);
        pub[u]=1;
    }
    for(int k=1;k<=n;k++){
        if(mark[k]) continue;
        dfs.push({k,0});
        mark[k]=1;
        while(!dfs.empty()){
            now=dfs.top();
            int ch=1;
            for(long long i=now.loop;i<g1[now.idx].size();i++){
                if(!mark[g1[now.idx][i]]){
                    mark[g1[now.idx][i]]=1;
                    dfs.top().loop = i;
                    dfs.push({g1[now.idx][i],0});
                    ch=0;
                    break;
                }
            }
            if(ch){
                dfs.pop();
                s.push(now.idx);
            }
        }
    }
    memset(mark,0,sizeof mark);
    long long group=0;
    while(!s.empty()){
        long long temp=s.top();
        s.pop();
        if(mark[temp])  continue;
        group++;
        dfs.push({temp,0});
        mark[temp]=1;
        while(!dfs.empty()){
            now=dfs.top();
            component_num[now.idx]=group;
            int ch=1;
            for(long long i=now.loop;i<inv[now.idx].size();i++){
                if(!mark[inv[now.idx][i]]){
                    mark[inv[now.idx][i]]=1;
                    dfs.top().loop = i;
                    dfs.push({inv[now.idx][i],0});
                    ch=0;
                    break;
                }
            }
            if(ch)
                dfs.pop();
        }
    }
    for(long long i=1;i<=n;i++){
        value[component_num[i]]+=money[i];
        if(pub[i])  stop[component_num[i]]=1;
        for(long long j=0;j<g1[i].size();j++)
            if(component_num[i]!=component_num[g1[i][j]])
                g2[component_num[i]].push_back(component_num[g1[i][j]]);
    }
    memset(mark,0,sizeof mark);
    memset(mic,-1,sizeof mic);
    mark[component_num[st]]=1;
    DFS(component_num[st]);
    printf("%lld\n",mic[component_num[st]]);
    return 0;
}
/*
6 7
1 2
2 3
3 5
2 4
4 1
2 6
6 5
10 12 8 16 1 5
1 4
4 3 5 6
*/
