/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
A now,a[300100];
vector< int> g[100100];
int c[100100];
bool dfs(int now,int col){
    if(c[now] && c[now]!=col)   return false;
    if(c[now])                  return true;
    c[now] = col;
    for(auto &x:g[now]){
        if(!dfs(x,3-col)){
            return false;
        }
    }
    return true;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&a[i].u,&a[i].v);
    int l = 1,r = m;
    while(l<r){
        int mid = (l+r)/2,ch = 1;
        for(int i=1;i<=mid;i++){
            g[a[i].u].push_back(a[i].v);
            g[a[i].v].push_back(a[i].u);
        }
        for(int i=1;i<=n;i++){
            if(c[i])    continue;
            if(!dfs(i,1)){
                ch = 0;
                break;
            }
        }
        if(ch)  l = mid+1;
        else    r = mid;
        memset(c,0,sizeof c);
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
    printf("%d\n",r);
	return 0;
}
