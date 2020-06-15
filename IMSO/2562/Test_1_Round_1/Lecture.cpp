/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL target[100010],tim[100010],dis[310][310];
int main(){
    LL c,n,m,u,v,w;
    scanf("%lld %lld %lld",&c,&n,&m);
    for(LL i=1;i<=c;i++)
        scanf("%lld",&target[i]);
    for(LL i=1;i<=c;i++)
        scanf("%lld",&tim[i]);
    for(LL i=1;i<=c;i++)
        tim[i]+=tim[i-1];
    for(LL i=1;i<=n;i++){
        for(LL j=1;j<=n;j++){
            if(i == j)  continue;
            dis[i][j] = 1e18;
        }
    }
    while(m--){
        scanf("%lld %lld %lld",&u,&v,&w);
        dis[u][v] = dis[v][u] = w;
    }
    for(LL k=1;k<=n;k++)
        for(LL i=1;i<=n;i++)
            for(LL j=1;j<=n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    LL l = 1,r = 1e18,mid,sum,ch;
    while(l<r){
        mid = (l+r+1)/2,sum = 0,ch = 1;
        for(LL i=1;i<c;i++){
            sum+=dis[target[i]][target[i+1]]*mid;
            sum = max(tim[i]+1,sum);
            if(sum>tim[i+1]){
                ch = 0;
                break;
            }
        }
        if(ch)  l = mid;
        else    r = mid-1;
    }
    printf("%lld\n",l);
    return 0;
}