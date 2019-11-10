/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        return v<o.v;
    }
};
vector<A > g[30];
int deg[30],ans[310],n,mark[30][30][310];
void dfs(int now,int state){
    ans[state] = now;
    if(state == n){
        for(int i=0;i<=n;i++)
            printf("%c ",ans[i]+'A');
        exit(0);
    }
    for(auto x:g[now]){
        if(mark[now][x.v][x.w])   continue;
        mark[now][x.v][x.w] = mark[x.v][now][x.w] = 1;
        dfs(x.v,state+1);
        mark[now][x.v][x.w] = mark[x.v][now][x.w] = 0;

    }
}
char str[3];
int main(){
    int countt = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",str);
        g[str[0]-'A'].push_back({str[1]-'A',i});
        g[str[1]-'A'].push_back({str[0]-'A',i});
        deg[str[0]-'A']++;
        deg[str[1]-'A']++;
    }
    for(int i=0;i<26;i++){
        sort(g[i].begin(),g[i].end());
        if(deg[i]%2 == 1)
            countt++;
    }
    if(countt == 2){
        for(int i=0;i<26;i++){
            if(deg[i]%2 == 1){
                dfs(i,0);
            }
        }
    }else{
        for(int i=0;i<26;i++){
            if(deg[i]!=0){
                dfs(i,0);
            }
        }
    }
	return 0;
}
