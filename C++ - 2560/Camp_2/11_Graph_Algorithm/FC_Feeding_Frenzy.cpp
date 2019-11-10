/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
#define MAXN 5001
using namespace std;
stack< int> st;
vector< int> adj[MAXN],adj2[MAXN];
int instack[MAXN],onstack[MAXN],cmp[MAXN],cmplvl[MAXN],lowlink[MAXN],idx[MAXN],TIME=0,CMPID=0,cnt[MAXN];
void dfs(int node){
    instack[node]=1;
    st.push(node);
    lowlink[node]=idx[node]=++TIME;
    for(int i=0;i<adj[node].size();i++){
        int next=adj[node][i];
        if(idx[next]==0){
            dfs(next);
            lowlink[node]=min(lowlink[node],lowlink[next]);
        }else if(instack[next]){
            lowlink[node]=min(lowlink[node],lowlink[next]);
        }
    }
    if(lowlink[node]==idx[node]){
        int w;
        CMPID++;
        while(st.top()!=node){
            w=st.top();
            instack[w]=0;
            cmp[w]=CMPID;
            st.pop();
        }
        w=st.top();
        st.pop();
        instack[w]=0;
        cmp[w]=CMPID;
    }
}
void dfs2(int cmp,int lvl){
    for(int i=0;i<adj2[cmp].size();i++){
        int next=adj2[cmp][i];
        if(lvl+1<=cmplvl[next])
            continue;
        else{
            cmplvl[next]=lvl+1;
            dfs2(next,lvl+1);
        }
    }
}
int main()
{
    int n,v;
    scanf("%d %d",&n,&v);
    for(int i=0;i<v;i++){
        int p,q;
        scanf("%d %d",&p,&q);
        adj[p].push_back(q);
    }
    for(int i=0;i<n;i++){
        if(idx[i]==0)
            dfs(i);
    }
    for(int i=0;i<n;i++){
        if(adj[i].size()>0)
        for(int j=0;j<adj[i].size();j++){
            if(cmp[i]!=cmp[adj[i][j]]){
                adj2[cmp[i]].push_back(cmp[adj[i][j]]);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(cmplvl[cmp[i]]==0){
            cmplvl[cmp[i]]=1;
            dfs2(cmp[i],1);
        }
    }
    for(int i=0;i<n;i++)
        cnt[cmplvl[cmp[i]]]++;
    for(int i=1;i<=n;i++)
        if(cnt[i]>0)
            printf("%d ",cnt[i]);
        else
            break;
    printf("\n%d",cmplvl[cmp[0]]);
    return 0;
}
