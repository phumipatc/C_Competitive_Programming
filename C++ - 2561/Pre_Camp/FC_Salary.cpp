/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[500010],tree[1000010],in[500010],out[500010],t = 1;
vector<int > g[500010];
void dfs(int now){
    in[now] = t++;
    for(auto x:g[now])
        dfs(x);
    out[now] = t++;
}
void update(int idx,int v){
    while(idx<=1000005){
        tree[idx]+=v;
        idx+=idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,m,u,w;
    char opr;
    scanf("%d %d %d",&n,&m,&a[1]);
    for(int i=2;i<=n;i++){
        scanf("%d %d",&a[i],&u);
        g[u].push_back(i);
    }
    dfs(1);
    while(m--){
        scanf(" %c",&opr);
        if(opr == 'p'){
            scanf("%d %d",&u,&w);
            update(in[u]+1,w);
            update(out[u],-w);
        }else{
            scanf("%d",&u);
            printf("%d\n",query(in[u])+a[u]);
        }
    }
	return 0;
}
