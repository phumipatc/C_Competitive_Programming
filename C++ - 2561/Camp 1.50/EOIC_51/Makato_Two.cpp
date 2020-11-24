/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[100005];
int a[100005],mark[100005],XOR[100005],p[100005];
void dfs(int now){
    mark[now] = 1;
    XOR[now] = a[now];
    for(auto &i:g[now]){
        if(mark[i]) continue;
		p[i] = now;
        dfs(i);
        XOR[now]^=XOR[i];
    }
}
int main(){
    int n,u,v,minn = 1e9,sum;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        sum = XOR[1]^XOR[i];
        for(auto &j: g[i]){
			if(j == p[i])	continue;
            sum+=XOR[j];
		}
        minn = min(minn,sum);
    }
    printf("%d\n",minn);
    return 0;
}
