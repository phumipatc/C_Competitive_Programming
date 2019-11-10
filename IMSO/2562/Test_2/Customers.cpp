/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
    int opr,v,w;
};
A a[240010];
vector<int > g[120010],gt[120010];
int shop[120010],cust[120010],val[120010],ans[120010];
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,m,q,num,v,maxx = 0;
    scanf("%d %d %d",&n,&m,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        while(num--){
            scanf("%d",&v);
            g[i].push_back(v);
            gt[v].push_back(i);
        }
    }
    return 0;
}