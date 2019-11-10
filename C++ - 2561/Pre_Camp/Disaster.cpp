/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,id;
    bool operator < (const A&o) const{
        return v<o.v;
    }
};
char a[5];
vector<A > g[30];
int n,mark[310],deg[30],ans[310];
void dfs(int now,int state){
    ans[state] = now;
    if(state == n){
        for(int i=0;i<=n;i++)
            printf("%c ",ans[i]+'A');
        exit(0);
    }
    for(auto x:g[now]){
        if(mark[x.id])  continue;
        mark[x.id] = 1;
        dfs(x.v,state+1);
        mark[x.id] = 0;
    }
}
int main(){
    int st = -1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",a);
        g[a[0]-'A'].push_back({a[1]-'A',i});
        g[a[1]-'A'].push_back({a[0]-'A',i});
        deg[a[0]-'A']++,deg[a[1]-'A']++;
    }
    for(int i=0;i<26;i++)
        sort(g[i].begin(),g[i].end());
    for(int i=0;i<26;i++){
        if(deg[i]%2){
            st = i;
            break;
        }else if(deg[i]>0 && st == -1){
            st = i;
        }
    }
    dfs(st,0);
	return 0;
}
