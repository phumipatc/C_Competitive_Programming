/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    unsigned long long v,percent,w;
};
vector<A > g[100010];
unsigned long long val[100010];
unsigned long long dfs(unsigned long long now,unsigned long long w){
    // printf("%llu %llu\n",now,w);
    if(val[now]){
        if(w<val[now])  return 0;
        else            return 1;
    }
    for(auto x:g[now]){
        unsigned long long num = (w*((long double )x.percent/100));
        if(num<x.w)         return 0;
        if(!dfs(x.v,num))   return 0;
    }
    return 1;
}
int main(){
    unsigned long long m,u,v,w,n,percent;
    scanf("%llu",&m);
    for(unsigned long long i=1;i<m;i++){
        scanf("%llu %llu %llu %llu",&u,&v,&percent,&w);
        g[u].push_back({v,percent,w});
    }
    scanf("%llu",&n);
    for(unsigned long long i=1;i<=n;i++){
        scanf("%llu %llu",&u,&v);
        val[u]+=v;
    }
    unsigned long long l = 1,r = LLONG_MAX;
    while(l<r){
        unsigned long long mid = (l+r)/2;
        // printf("%llu %llu : %llu\n",l,r,mid);
        if(dfs(1,mid))  r = mid;
        else            l = mid+1;
    }
    printf("%llu\n",l);
	return 0;
}
/*
8
1 2 70 40
1 3 30 20
2 4 30 45
2 5 40 30
2 6 30 12
5 7 50 8
5 8 50 12
5
4 4
7 5
8 8
6 3
3 3
*/