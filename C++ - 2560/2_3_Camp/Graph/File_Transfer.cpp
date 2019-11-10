/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[1100];
int mark[1100];
void transfer(int now){
    for(int i=0;i<g[now].size();i++){
        if(mark[g[now][i]]==0){
            mark[g[now][i]]=1;
            transfer(g[now][i]);
        }
    }
}
int main(){
    int n,m,q,u,v,st,en;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
    }
    while(q--){
        scanf("%d %d",&st,&en);
        memset(mark,0,sizeof mark);
        mark[st]=1;
        transfer(st);
        if(mark[en]==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
