/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100010];
int in[100010],lv[100010],p[100010][22];
void dfs(int now,int lvl){
    lv[now] = lvl;
    for(int i=1;i<=20;i++)
        p[now][i] = p[p[now][i-1]][i-1];
    for(auto x:g[now]){
        if(lv[x])   continue;
        dfs(x,lvl+1);
    }
}
int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        p[v][0] = u;
        g[u].push_back(v);
        in[v]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i])   continue;
        if(lv[i])   continue;
        dfs(i,1);
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=20;j++){
    //         printf("%d ",p[i][j]);
    //     }
    //     printf("\n");
    // }
    int q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&u,&v);
        if(lv[u]>lv[v]) swap(u,v);
        // printf("%d %d\n",u,v);
        for(int i=20;i>=0;i--){
            if(lv[p[v][i]]<lv[u])   continue;
            v = p[v][i];
        }
        // printf("%d %d\n",u,v);
        if(u == v){
            printf("%d\n",u);
            continue;
        }
        for(int i=20;i>=0;i--){
            if(p[u][i] == p[v][i])  continue;
            u = p[u][i],v = p[v][i];
        }
        // printf("%d %d\n",u,v);
        printf("%d\n",p[u][0]);
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
*/