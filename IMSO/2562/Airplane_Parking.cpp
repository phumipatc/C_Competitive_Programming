/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > comp;
pair<int ,int > p[310];
int dp[610][610],plane[610][610];
int divide(int l,int r){
    if(l == r)          return plane[l][r];
    if(dp[l][r]!=-1)    return dp[l][r];
    int ret = 0;
    for(int k=l;k<r;k++)
        ret = max(ret,divide(l,k)+divide(k+1,r));
    return dp[l][r] = ret+plane[l][r];
}
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0);
    int q,n,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&p[i].first,&p[i].second);
            p[i].second--;
            comp.push_back(p[i].first);
            comp.push_back(p[i].second);
        }
        sort(comp.begin(),comp.end());
        comp.resize(unique(comp.begin(),comp.end())-comp.begin());
        for(int i=1;i<=n;i++){
            l = upper_bound(comp.begin(),comp.end(),p[i].first)-comp.begin();
            r = upper_bound(comp.begin(),comp.end(),p[i].second)-comp.begin();
            plane[l][r]++;
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n",divide(1,comp.size()));
        memset(plane,0,sizeof plane);
        comp.clear();
    }
    return 0;
}