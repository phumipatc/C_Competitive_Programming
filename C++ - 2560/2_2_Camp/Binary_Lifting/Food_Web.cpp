/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
int in[100100],mic[25][100100],lv[100100];
void dfs(int now,int state){
    mic[0][now]=state;
    lv[now]=lv[state]+1;
    for(auto &i : g[now])
        dfs(i,now);
}
int LCA(int a,int b){
    if(lv[a]>lv[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        if(lv[mic[i][b]]<lv[a]) continue;
        b=mic[i][b];
    }
    if(a==b)    return a;
    for(int i=20;i>=0;i--){
        if(mic[i][a]!=mic[i][b])
            a=mic[i][a],b=mic[i][b];
    }
    return mic[0][a];
}
int main(){
    int n,q,s,e;
    memset(mic,-1,sizeof mic);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        g[s].push_back(e);
        in[e]++;
    }
    for(int i=1;i<=n;i++){
        if(in[i]==0)
            dfs(i,0);
    }
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            mic[i][j]=mic[i-1][mic[i-1][j]];
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&s,&e);
        printf("%d\n",LCA(s,e));
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
