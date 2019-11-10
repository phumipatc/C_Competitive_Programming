/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
long long sum[100100],mark[100100];
vector<long long> vect[100100];
void dfs(long long u){
    if(mark[u]==1)  return ;
    mark[u]=1;
    for(long long i=0;i<vect[u].size();i++){
        if(mark[vect[u][i]]==0){
            dfs(vect[u][i]);
            sum[u]+=sum[vect[u][i]];
//            printf("now = %lld\nnext = %lld\nsum now = %lld\nsum next = %lld\n",u,vect[u][i],sum[u],sum[vect[u][i]]);
        }
    }
    return ;
}
int main()
{
    long long q,n,i,a,b,ans;
    scanf("%lld",&q);
    while(q--){
        ans=100000000000000;
        scanf("%lld",&n);
        for(i=1;i<n;i++){
            scanf("%lld %lld",&a,&b);
            vect[a].push_back(b);
            vect[b].push_back(a);
        }
        for(i=1;i<=n;i++)
            scanf("%lld",&sum[i]);
        dfs(1);
        for(i=1;i<=n;i++){
            ans=min(ans,abs(sum[1]-(2*sum[i])));
        }
        printf("%lld\n",ans);
        for(i=0;i<=n;i++){
            vect[i].clear();
        }
        memset(sum,0,sizeof sum);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
/*
2
6
1 2
1 3
1 5
5 6
6 4
2 1 3 3 4 6
*/
