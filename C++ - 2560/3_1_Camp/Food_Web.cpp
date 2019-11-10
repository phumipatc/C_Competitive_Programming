/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100010];
int lv[100010],in[100010],dp[22][100010];
void dfs(int now,int state){
    dp[0][now] = state;
    lv[now] = lv[state]+1;
    for(auto i:g[now])
        dfs(i,now);
}
int main(){
    int n,q,u,v,a,b;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        in[v]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])
            dfs(i,0);
    for(int i=1;i<=20;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = dp[i-1][dp[i-1][j]];
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        if(lv[a]>lv[b]) swap(a,b);
        for(int i=20;i>=0;i--){
            if(lv[dp[i][b]]<lv[a])  continue;
            b = dp[i][b];
        }
        if(a == b){
            printf("%d\n",a);
            continue;
        }
        for(int i=20;i>=0;i--)
            if(dp[i][a]!=dp[i][b])
                a = dp[i][a],b = dp[i][b];
        printf("%d\n",dp[0][a]);
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
