/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long d[5000100],in[5000100],out[5000100],tree[1000100],ti=1,n;
vector< long long> pa[5001000];
void dfs(long long v)
{
    in[v]=ti++;
    for(long long i=0;i<pa[v].size();i++)
        dfs(pa[v][i]);
    out[v]=ti++;
}
void update(long long idx,long long value){
    while(idx<=1000000){
        tree[idx]+=value;
        idx+=(idx&-idx);
    }
}
long long query(long long idx){
    long long sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main(){
    char opr;
    long long m,a,b,i;
    scanf("%lld %lld %lld",&n,&m,&d[1]);
    for(i=2;i<=n;i++)
    {
        scanf("%lld %lld",&d[i],&b);
        pa[b].push_back(i);
    }
    dfs(1);
    for(i=1;i<=m;i++){
        scanf(" %c",&opr);
        if(opr=='p'){
            scanf("%lld %lld",&a,&b);
            update(in[a]+1,b);
            update(out[a]+1,-b);
        }else{
            scanf("%lld",&a);
            printf("%lld\n",query(in[a])+d[a]);
        }
    }
    return 0;
}
/*
9 0
1
2 1
3 2
4 2
5 1
6 2
7 5
8 1
9 4

5 5
4
2 1
6 1
7 1
3 4
u 3
p 1 -1
u 3
p 4 5
u 5
*/
