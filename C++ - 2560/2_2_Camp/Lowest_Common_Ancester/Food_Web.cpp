/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> in[100100],out[100100];
int RMQ[50][200100],euler[200100],level[200100],h[100100],now=0;
void dfs(int u,int state){
    euler[now]=u;
    level[now]=state;
    now++;
    for(int i=0;i<out[u].size();i++){
        dfs(out[u][i],state+1);
        euler[now]=u;
        level[now]=state;
        now++;
    }

}
int main(){
    int n,i,j,u,v,root=1,q;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        in[v].push_back(u);
        out[u].push_back(v);
    }
    for(i=1;i<=n;i++){
        if(in[i].size()==0){
            root=i;
            break;
        }
    }
    dfs(root,0);
    memset(h,-1,sizeof h);
    for(i=1;i<=200000;i++){
        if(h[euler[i]]==-1)
            h[euler[i]]=i;
        RMQ[0][i]=i;
    }
    for(i=1;i<=log2(now);i++){
        for(j=0;j<now;j++){
            if(j+(1<<(i))<=now){
                if(level[RMQ[i-1][j]]<level[RMQ[i-1][j+(1<<(i-1))]])
                    RMQ[i][j]=RMQ[i-1][j];
                else
                    RMQ[i][j]=RMQ[i-1][j+(1<<(i-1))];
            }
        }
    }
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
    if(h[a]>h[b])   swap(a,b);
    int k=log2(h[b]-h[a]+1);
    if(level[RMQ[k][h[a]]]<level[RMQ[k][h[b]-(1<<k)+1]])
        printf("%d\n",euler[RMQ[k][h[a]]]);
    else
        printf("%d\n",euler[RMQ[k][h[b]-(1<<k)+1]]);
    }
    return 0;
}
/*
13
1 2
1 3
2 9
2 6
2 8
6 10
6 5
3 7
7 11
7 13
13 4
13 12
5
10 5
11 12
9 7
10 8
9 8
*/
